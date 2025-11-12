#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int book[5005]={};
long long ans=0;
void dfs(int x,int y)
{
    if(x==n+1)
    {
        long long sum=0;
        int maxx=INT_MIN;
        for(int i=1;i<=n;i++)
            if(book[i]==1)
            {
                sum+=a[i];
                maxx=max(maxx,a[i]);
            }
        int lest=ans;
        if(sum>2*maxx)
            ans++;
        ans%=998244353;/*
        if(ans!=lest)
        {
            for(int i=1;i<=n;i++)
                if(book[i]==1)
                {
                    cout<<a[i]<<" ";
                }
            cout<<"\n";
        }
        cout<<ans<<"\n";*/
        return;
    }
    book[x]=1;
    dfs(x+1,y);
    book[x]=0;
    dfs(x+1,y);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==3)
    {
        if(a[1]+a[2]>a[3] && a[2]+a[3]>a[1] && a[1]+a[3]>a[2])
            cout<<1;
        else
            cout<<0;
        return 0;
    }
    dfs(1,1);
    cout<<ans;
    return 0;
}
