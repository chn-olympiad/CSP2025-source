#include<bits/stdc++.h>
using namespace std;
int a[100010],f[100010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,s2=0,s1=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)s1++;
        if(a[i]==0)s2++;
    }
    if(k==0 && n==1)
    {
        if(a[1]==1)cout<<0;
        if(a[1]==0)cout<<1;
    }
    else if(k==0 && n==2)
    {
        if(s1==2)cout<<1;
        if(s1==1)cout<<0;
        if(s2==2)cout<<0;
    }
    else if(k==0 && n>2)
    {
        int s=0;
        for(int i=1;i<=n-1;i++)
        {
            if(a[i]==0)s++;
            if(a[i]==1 && a[i+1]==1 && f[i]==0)
            {
                s++;
                f[i+1]=1;
            }
        }
        cout<<s;
    }
    if(k==1 && n==1)
    {
        if(a[1]==1)cout<<1;
        if(a[1]==0)cout<<0;
    }
    else if(k==1 && n==2)
    {
        if(s1==2)cout<<0;
        if(s1==1)cout<<1;
        if(s2==2)cout<<1;
    }
    else if(k==1 && n>2)
    {
        cout<<s1;
    }
}
