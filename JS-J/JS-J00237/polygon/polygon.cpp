#include<bits/stdc++.h>
using namespace std;
int a[5005],n;
long long ans=0,M=998244353;
void dfs(int k,int maxx,int sum,int dep,int last)
{
    if(dep>k)
    {
        if(sum>2*maxx)
        {
            ans++;
            ans=ans%M;
        }
    }
    else
    {
        for(int i=last+1;i<=n-k+dep;i++)
        {
            dfs(k,a[i],sum+a[i],dep+1,i);
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++)
    {
        dfs(i,0,0,1,0);
    }
    cout<<ans;
    return 0;
}
