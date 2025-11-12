#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using ll=long long;
constexpr int MAX_N=500, MOD=998244353;

int n, m;
int c[MAX_N+10];
bool ar[MAX_N+10], vis[MAX_N+10];
char input;

int ans;

void dfs(int i, int now,int drop);

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>input;
        if(input=='1')
        {
            ar[i]=true;
        }
        //cout<<ar[i];
    }

    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }

    ar[0]=true;
    dfs(0, 0, 0);
    cout<<ans<<endl<<std::flush;
    return 0;
}

void dfs(int i, int now,int drop)
{
    if((drop>=c[now])||(ar[i]==false))
    {
        drop++;
    }
    if(i==0)
    {
        drop--;
    }
    std::cerr<<i<<now<<drop<<endl;
    if(drop>n-m)
    {
        return;
    }
    if(i==n)
    {
        ans++;
        ans%=MOD;
        return;
    }

    for(int j=1;j<=n;j++)
    {
        if(vis[j]==false)
        {
            vis[j]=true;
            dfs(i+1, j, drop);
            vis[j]=false;
        }
    }
}
