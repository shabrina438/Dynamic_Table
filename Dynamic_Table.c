#include <stdio.h>

int *table,len;
void init()
{
    table=NULL;
    len=0;
}

void destroy(int *b)
{
    if(b!=NULL)
    {
        free(b);
    }
}

void insert()
{
    int num;
    printf("Enter value: ");
    scanf("%d",&num);
    len++;
    if((table=(int*)realloc(table,len*sizeof(int)))==0){
        printf("Error");
    }
    table[len-1]=num;
}

void display()
{
    int x;
    for(x=0;x<len;x++)
    {
        printf(" %d\n",table[x]);
    }
}

int sum()
{
    int i,sum=0;
    for(i=0;i<len;i++)
    {
        sum += table[i];
    }
    return(sum);
}

int find(int num)
{
    int i;
    for(i=0;i<len;i++){
        if(table[i]==num)
        {
            return(i);
        }
    }
    return(-1);
}

int maximum()
{
    int i,max;
    max=table[0];
    for(i=1;i<len;i++)
    {
        if (table[i]>max)
        {
            max=table[i];
        }
    }
    return(max);
}

int minimum()
{
    int i,min;
    min=table[0];
    for(i=1;i<len;i++){
        if (table[i]<min)
        {
            min=table[i];
        }
    }
    return(min);
}

int reverse()
{
    int x,i,temp;
    printf("Elements in table: \n");
    for(x=0;x<len;x++){
        printf(" %d\n",table[x]);
    }
    for(i=0;i<x/2;i++){
        temp = table[i];
        table[i] = table[x-i-1];
        table[x-i-1] = temp;
    }
    printf("Reversing the order of the table: \n");
    for(i=0;i<x;i++){
        printf(" %d\n",table[i]);
    }
}

void sorting()
{
    int *ptr[len],*tmp,i,j;
    for(i=0;i<len;i++)
    {
        ptr[i]=&table[i];
    }
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(*ptr[j]<*ptr[i])
            {
                tmp=ptr[i];
                ptr[i]=ptr[j];
                ptr[j]=tmp;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        printf("%d: %d\n",i+1,*ptr[i]);
    }
}

int remove_value(int num)
{
    int x;
    x=find(num);
    if(x==-1){
        return(-1);
    }
    else{
        table[x]=table[len-1];
        len--;
        table=(int*)realloc(table,len*sizeof(int));
        return(1);
    }
}

int main()
{
    int out,choice,num;
    init();
    do
    {
        putchar('\n');
        printf("    Dynamic Table\n");
        printf("------------------------\n");
        printf(" 1: Insert number\n");
        printf(" 2: Sum of elements\n");
        printf(" 3: Find Number\n");
        printf(" 4: Print max number\n");
        printf(" 5: Print min number\n");
        printf(" 6: Sort table\n");
        printf(" 7: Delete number\n");
        printf(" 8: Print Reverse number\n");
        printf(" 9: Print table\n");
        printf(" 0: Exit\n");
        printf(" \n");

        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("\nInsert numbers to table:\n");
                printf("\n");
                insert();
                break;
            }
            case 2:
            {
                out=sum();
                printf("\nSum of all numbers is: %d\n",out);
                break;
            }
            case 3:
            {
                printf("\nEnter searching number: ");
                scanf("%d",&num);
                printf("The number is: %d",num);
                printf("\n");
                out=find(num);
                if(out==-1)
                {
                    printf("Not found the number in table\n");
                }
                else
                {
                    printf("Number is at position: %d\n",out+1);
                }
                break;
            }
            case 4:
            {
                out=maximum();
                printf("Maximum number is: %d\n",out);
                break;
            }
            case 5:
            {
                out=minimum(0,table);
                printf("Minimum number is: %d\n",out);
                break;
            }
            case 6:
            {
                printf("\nSorted table: \n");
                sorting();
                break;
            }
            case 7:
            {
                printf("\nGive number to delete: ");
                scanf("%d",&num);
                out=remove_value(num);
                if(out==1)
                {
                    printf("\nNumber %d has been deleted.\n",num);
                }
                else
                {
                    if(out==-1)
                    {
                        printf("\nNumber %d don't exist.\n",num);
                    }
                    else
                    {
                        printf("\nNumber did not deleted %d.\n",num);
                    }
                }
                break;
            }
            case 8:
            {
                reverse();
                break;

            }
            case 9:
            {
                printf("\nPrint Table:\n");
                display();
                break;
            }
        }
    }

    while(choice!=0);
    destroy(table);
    exit(0);
}

