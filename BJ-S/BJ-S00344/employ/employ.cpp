#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
char c[N];
int a[N];
int n,m;
int box[N];
bool vis[N];
long long ans=0;
void dfs(int cur)
{
    if(cur>n)
    {
        int cnt=0;
        int num=0;
        for(int i=1;i<=n;i++)
        {
            int x=box[i];
            if(cnt<a[x] && c[i]=='1') num++;
            else cnt++;
        }
        if(num>=m) ans++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            box[cur]=i;
            vis[i]=1;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++) cin >>c[i];
    for(int i=1;i<=n;i++) cin >>a[i];
    dfs(1);
    cout <<ans%998244353;
    return 0;
}
