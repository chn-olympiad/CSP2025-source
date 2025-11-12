#include<bits/stdc++.h>
using namespace std;
int a[505],vis[505],n,m,x,ans,v[505];
const long long P=998244353;
string s;
void dfs(int dep)
{
    if (dep==n+1)
    {
        int res=0,sum=0;
        for (int i=1;i<=n;i++)
            if (res<v[a[i]] and s[i]=='1') sum++;
            else res++;
        if (sum==m) ans++;
        return ;
    }
    for (int i=1;i<=n;i++)
    {
        if (vis[i]) continue;
        vis[i]=1;
        a[dep]=i;
        dfs(dep+1);
        vis[i]=a[dep]=0;
    }
}
long long f(int n)
{
    long long res=1;
    for (int i=2;i<=n;i++) res=res*i%P;
    return res;
}
int main()
{
    cin>>n>>m;
    cin>>s;
    if (n==m)
    {
        for (int i=1;i<=n;i++) cin>>x;
        for (int i=1;i<=n;i++)
            if (s[i]=='0')
            {
                cout<<0;
                return 0;
            }
        cout<<f(n);
        return 0;
    }
    for (int i=1;i<=n;i++) cin>>v[i];
    dfs(1);
    cout<<ans;
    return 0;
}
