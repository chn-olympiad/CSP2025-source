#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i = l;i<=r;i++)
#define LL long long
const int N = 205,M = 1e5+5;
int n,t;
int p[N],q[N];
int vis[N];
LL ans,a[N][5],st[M],f[N][4][N/2];
// f[i][j][k] --> max(f[i-1][1~3][k-(pj==j)])+a[i][j]
// k
void dfs(int x)
{
    if(x > n)
    {
        LL sum = 0;
        for(int i = 1;i<=3;i++) p[i] = 0;
        for(int i = 1;i<=n;i++)
        {
            p[vis[i]]++;
            if(p[vis[i]] > n/2) return;
            sum += a[i][vis[i]];
        }
        ans = max(ans,sum);
        return;
    }
    vis[x] = 1;
    dfs(x+1);
    vis[x] = 2;
    dfs(x+1);
    vis[x] = 3;
    dfs(x+1);
}
int main()
{
     freopen("club.in","r",stdin);
     freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>n;
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=3;j++)
                cin>>a[i][j];
        if(n <= 10)
        {
            dfs(1);
            cout << ans << '\n';
            continue;
        }
        if(n == 1e5)
        {
            LL res = 0;
            for(int i = 1;i<=n;i++) st[i] = a[i][1];
            sort(st+1,st+n+1);
            for(int i = n;i>=n/2;i--) res += st[i];
            cout << res << '\n';
            continue;
        }
        memset(f,-0x3f,sizeof f);
        for(int i = 1;i<=3;i++) f[0][i][0] = 0;
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=3;j++)
                for(int k = 1;k<=min(i,n/2);k++)
                    for(int pj = 1;pj<=3;pj++)
                    {
                        if(pj == j) f[i][j][k] = max(f[i][j][k],f[i-1][pj][k-1]+a[i][j]);
                        else
                        {
                            for(int pk = 0;pk<=min(i-k,n/2);pk++)
                                if(k+pk<=i) f[i][j][k] = max(f[i][j][k],f[i-1][pj][pk]+a[i][j]);
                        }
                    }
        LL ans = 0;
        for(int j = 1;j<=3;j++) for(int k = 0;k<=n/2;k++) ans = max(ans,f[n][j][k]);
        cout << ans << '\n';
    }
    return 0;
}