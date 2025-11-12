#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int i,j,n,m=-1,maxn,maxnn,a[1000001];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    gets(s);
    n=sizeof(s);
    for(i=0;i<n;i++)
     if((s[i]-'0')>=1&&(s[i]-'0')<=9)
    {
        m++;
        a[m]=s[i]-'0';
    }
    for(i=0;i<m;i++)
    {
        maxn=a[i+1];
        for(j=i+1;j<=m;j++)
            if(a[j]>maxn)
            {
             maxn=a[j];
             maxnn=j;
            }
        if(a[i]<a[maxnn])swap(a[i],a[maxnn]);
    }
    for(i=0;i<=m;i++)
        cout<<a[i];
    return 0;
}
