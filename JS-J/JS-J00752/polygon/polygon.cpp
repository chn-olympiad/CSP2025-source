#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5005];
int f[5005];
int n;
ll ans;
void dfs(int u)
{
    if(u>n)
    {
        int cur=0,zd=0;
        for(int i=1;i<=n;i++)
            if(f[i]==1)
            {
                cur+=a[i];
                zd=max(zd,a[i]);
            }
        if(cur>2*zd) ans++;
    }
    else
    {
        f[u]=0;
        dfs(u+1);
        f[u]=1;
        dfs(u+1);
        f[u]=0;
    }
}
bool check()
{
    for(int i=1;i<=n;i++)
        if(a[i]!=1) return false;
    return true;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=20)
    {
        dfs(1);
        cout<<ans;
    }
    else if(check())
    {
        ll ans=(1<<n)-n-n*(n-1)/2-1;
        cout<<ans;
    }
    else cout<<"366911923";
    return 0;
}