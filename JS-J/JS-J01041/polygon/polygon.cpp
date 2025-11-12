#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n;
int a[5005];
bool vis[5005];
long long ans=0;
int f[5005];
void dfs(int x,int maxn,int sum)
{
    if(x>=3&&maxn*2<sum)
    {
        for(int i=1;i<=x;i++)
        {
            cout<<f[i]<<" ";
        }
        cout<<endl;
        ans++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&i>f[x])
        {
            f[x+1]=i;
            vis[i]=true;
            dfs(x+1,a[i],sum+a[i]);
            vis[i]=false;
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
    dfs(0,0,0);
    cout<<ans<<endl;
    return 0;
}
