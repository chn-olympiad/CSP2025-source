#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const ll N = 205,M = 1e5+5;

ll T,n,a[M][3],dp[N][N][N],ans,b[M];
bool tp1,tp2;
struct node
{
    ll pos,val;
    node(){}
    node(ll x,ll y):pos(x),val(y) {}
    bool operator < (const node &x) const
    {
        return x.val<val;
    }
};
priority_queue<node> q;

ll read()
{
    char c = getchar();
    ll ch=0;
    while(c<'0'||c>'9') c = getchar();
    while(c>='0'&&c<='9')
    {
        ch = (ch<<3)+(ch<<1)+c-'0';
        c = getchar();
    }
    return ch;
}

void reset()
{
    memset(dp,0,sizeof dp);
    tp1 = tp2 = 0;
    ans = 0;
}

void solve1()
{
    for(ll i=1;i<=n;i++) b[i] = a[i][0];
    sort(b+1,b+1+n,greater<ll>());
    for(ll i=1;i<=n/2;i++) ans += b[i];
    cout << ans << '\n';
}

void solve2()
{
    for(ll i=1;i<=n;i++) q.push(node(i,a[i][1]-a[i][0]));
    for(ll i=1;i<=n/2;i++)
    {
        ans += a[q.top().pos][0];
        q.pop();
    }
    for(ll i=1;i<=n/2;i++)
    {
        ans += a[q.top().pos][1];
        q.pop();
    }
    cout << ans << '\n';
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T = read();
    while(T--)
    {
        reset();
        n = read();
        for(ll i=1;i<=n;i++)
        {
            a[i][0] = read();
            a[i][1] = read();
            a[i][2] = read();
            if(a[i][1]>0||a[i][2]>0) tp1 = 1;
            if(a[i][2]>0) tp2 = 1;
        }
        if(!tp1)
        {
            solve1();
            continue;
        }
        if(!tp2)
        {
            solve2();
            continue;
        }
        for(ll i=1;i<=n;i++)//1,2
        {
            for(ll j=n/2;j>=0;j--)//1,0
            {
                for(ll k=n/2;k>=0;k--)//1,0
                {
                    if(i-j-k>0) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+a[i][0]);
                    if(j>0) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
                    if(k>0) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
                }
            }
        }
        for(ll i=0;i<=n/2;i++)
        {
            for(ll j=n/2;j>=0&&i+j>=n/2;j--)
            {
                ans = max(ans,dp[n][i][j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
