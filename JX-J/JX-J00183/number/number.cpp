#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s[100];
    int a[1000]={10},p=0,n,q=0;
    while(s[q]!=" ")
    {
        cin>>s[q];
        q++;
    }
    for(int i=1;i<=q;i++)
    {
        if('s[i]'>='a'&&'s[i]'<='z');
        {
            int s[i];
            s[i]=100;
        }
    }
    for(int i=1;i<=q;i++)
    {
        int s[i];
        n=s[i]%10;
        if(n>=0&&n<=9)
         {
            a[n]++;
         }
    }
    for(int i=9;i>=0;i--)
    {
        if(a[i]>10)
        {
            for(int c=1;c<=a[i]-10;c++)
            {
                    p=p*10+i;
            }
        }
    }
    cout<<p;
    return 0;
}

