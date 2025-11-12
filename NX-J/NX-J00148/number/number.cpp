#include<iostream>
using namecpace std;
int N=1000000;
int main()
{
    char s[N];
    int b,number[N],c=1;
    for(int i=0;i<N,i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<N;i++)
    {
        if(s[i]=="0"||s[i]=="1"||s[i]=="2"||s[i]=="3"||s[i]=="4"||s[i]=="5"||s[i]=="6"||s[i]=="7"||s[i]=="8"||s[i]=="9")
        {
            number[i]=int(s[i]);
            b+=1;
        }
    }
    for(int i=0;i<b;i++)
    {
        for(int i=1;i<b;i++)
        {
            if(number[i]>number[i-1])
            {
            	c=number[i];
            	number[i]=number[i-1];
            	number[i-1]=c;
            }
        }
    }
    for(int i=0;i<b;i++)
    {
    	cout<<number[i];
    }
    return 0;
}
