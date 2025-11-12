#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans,mod=998244353;
void dfs(int k,int sum,int cnt,int last)
{
    if(k>n)return;
    if(last==k-1&&cnt>=3)
    {
        if(2*a[last]<sum)
        {
            ans=(ans+1)%mod;
        }
    }
    dfs(k+1,sum,cnt,last);
    dfs(k+1,sum+a[k],cnt+1,k);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
