#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD=998244353;
int n,m,c[505],a[505],h[505];
bool book[505];
string s;
int dfs(int x,int sum,int su)
{
    if (x>n) return sum>=m;
    int res=0;
    for (int i=1;i<=n;i++)
    {
        if (book[i]==0)
        {
            if (s[x-1]=='0' && sum+h[x+1]<m) continue;
            if (s[x-1]=='1' && sum+h[x+1]+1<m) continue;
            if (su>=c[i] || s[x-1]=='0')
                book[i]=1,res=(res+dfs(x+1,sum,su+1))%MOD,book[i]=0;
            else
                book[i]=1,res=(res+dfs(x+1,sum+1,su))%MOD,book[i]=0;
        }
    }
    return res;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m),cin >> s;
    for (int i=n;i>=1;i--) h[i]=h[i+1]+(s[i-1]=='1');
    for (int i=1;i<=n;i++) scanf("%lld",&c[i]);
    printf("%lld",dfs(1,0,0));
    return 0;
}