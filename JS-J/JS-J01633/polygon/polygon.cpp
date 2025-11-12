#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
void dfs(int dep,int s,int maxi)
{
    if(dep>n)
    {
        if(s>maxi*2) ans++;
        return ;
    }
    dfs(dep+1,s,maxi);
    dfs(dep+1,s+a[dep],max(maxi,a[dep]));
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(a[n]==1)
    {
        long long s1=n,s2=1;
        for(int i=1; i<=4; i++)
        {
            s2*=s1;
            s2%=998244353;
            s1--;
        }
        cout<<s2;
    }
    else
    {
        dfs(1,0,0);
        cout<<ans;
    }
    return 0;
}
