#include <bits/stdc++.h>
using namespace std;
int n,a[5005],s;
/*void dfs(int b,int c,int d,int e)//b max c sum d at e number
{
    for(int i=d+1;i<n;i++)
    {
        if(e<3)
        {
            if(a[i]>b)dfs(a[i],c+a[i],i,e+1);
        }
        else
        {
            if(a[i]<c)
            {
                if(a[i]>b)dfs(a[i],c+a[i],i,e+1);
                else if(a[i]>b)dfs(b,c+a[i],i,e+1);
                s++;
                s=s%998244353;
            }
            if(a[i]<=c)
            {
                if(a[i]>b)dfs(a[i],c+a[i],i,e+1);
                else if(a[i]>b)dfs(b,c+a[i],i,e+1);
            }
        }
    }
    return;
}*/
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int k=n-1;k>=i+1;k--)
        {
            if(a[k]<a[k-1])swap(a[k],a[k-1]);
        }
    }
    if(a[2]>=a[0]+a[1])
    {
        cout<<0;
    }
    else cout<<1;
    /*for(int i=0;i<n;i++)
    {
        dfs(a[i],a[i],i,1);
    }
    cout<<s;*/
    return 0;
}
