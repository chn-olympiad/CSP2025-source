#include <bits/stdc++.h>
#define ll long long
#define P 998244353
using namespace std;
int a[5005];
int n,ans;

ll f(int x)
{
    ll ans=1;
    for(int i=1;i<=x;i++)
        ans=(ans<<1)%P;
    ans=ans-x*(x+1)/2-x-1;
    return (ans+P)%P;
}

ll dfs(int dep,int cnt,int sum,int mx)
{
    if(dep>n)
    {
        if(cnt>2 && sum>mx*2)
            return 1;
        return 0;
    }
    return (dfs(dep+1,cnt,sum,mx)+
    dfs(dep+1,cnt+1,sum+a[dep],max(mx,a[dep])) )%P;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;

    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) flag=0;
    }
    
    if(flag)
        cout<<f(n)<<'\n';
    else
        cout<<dfs(1,0,0,0)<<'\n';

    return 0;
}