#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int n=0,s=0;
    freopen("number.in","r",stdin);
    getline(cin,a);
    while(a[n]!='\0')
    {
        n++;
        if(char(a[n])>='0' && char(a[n])<='9')
            s++;
    }
    n=0;
    char sz[s];
    int m=0;
    while(a[n]!='\0')
    {
        n++;
        if(char(a[n])>='0' && char(a[n])<='9')
        {
            sz[m]=int(a[n]);
            m++;
        }
    }
    if(char(a[0])>='0' && char(a[0])<='9')
    {
        sz[s]=a[0];
        s++;
    }
    int i,j,c,k=0;
    for(i=0;i<s;i++)
    {
        for(j=0;j<s;j++)
        {
            if(sz[j]<=sz[j+1])
            {
                c=sz[j];
                sz[j]=sz[j+1];
                sz[j+1]=c;
            }
        }
    }
    for(i=0;i<s;i++)
        k=k*10+(sz[i]-48);
    freopen("number.out","w",stdout);
    cout<<k;
    return 0;
}

