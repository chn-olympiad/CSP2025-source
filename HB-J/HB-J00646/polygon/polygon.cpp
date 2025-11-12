#include <bits/stdc++.h>
using namespace std;
long long n,a[5005];
bool vis[5005];
long long cnt;
void dfs(int id,long long maxn)
{
    if(id>n+1)
        return;
    if(id==n+1)
    {
        long long sum=0;
        for(int i=1;i<=n;i++)
            if(vis[i])
                sum+=a[i];
        if(sum>maxn*2)
        {
            cnt++;
            cnt%=998244353;
        }
    }
    dfs(id+1,maxn);
    vis[id]=1;
    dfs(id+1,max(maxn,a[id]));
    vis[id]=0;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    dfs(1,0);
    cout << cnt%998244353;
    return 0;
}
