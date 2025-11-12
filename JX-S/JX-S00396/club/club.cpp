#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int T;
int n,ans = -1;
int a[maxn],b[maxn],c[maxn];
bool vis[maxn];
bool f;
void dfs(int now,int sum1,int sum2,int sum3,int sum)
{
    if(now > n) {ans = max(ans,sum);return ;}
    if(sum1 + 1 <= n /2 && !vis[now]) vis[now] = 1,dfs(now + 1,sum1 + 1,sum2,sum3,sum + a[now]),vis[now] = 0;
    if(sum2 + 1 <= n /2 && !vis[now]) vis[now] = 1,dfs(now + 1,sum1,sum2 + 1,sum3,sum + b[now]),vis[now] = 0;
    if(sum3 + 1 <= n /2 && !vis[now]) vis[now] = 1,dfs(now + 1,sum1,sum2 + 1,sum3,sum + c[now]),vis[now] = 0;
}
void solve()
{
    ans = -1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d%d%d",&a[i],&b[i],&c[i]);if(b[i] || c[i]) f = 1;}
    if(!f)
    {
        sort(a + 1,a + 1 + n,greater<int>());
        for(int i=1;i<=n/2;i++) ans += a[i];
        printf("%d\n",ans + 1);
        return ;
    }
    dfs(1,0,0,0,0);
    printf("%d\n",ans);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T --) solve();
    return 0;
}