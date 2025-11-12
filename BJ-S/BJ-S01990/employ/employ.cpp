#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN = 510,mod = 998244353;
int n,m,s[MAXN],c[MAXN],ans,vis[MAXN],p[MAXN];
void dfs(int x) {
    if(x==n+1) {
        int cnt = 0,sum = 0;
        for(int i = 1;i<=n;i++) {
            if(cnt>=c[p[i]])   cnt++;
            else if(s[i])   sum++;
            else    cnt++;
        }
        if(sum>=m)  ans = (ans+1)%mod;
        return;
    }
    for(int i = 1;i<=n;i++)
        if(vis[i]==0) {
            vis[i] = 1,p[x] = i;
            dfs(x+1);
            vis[i] = 0,p[x] = 0;
        }
}
signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) {char c;cin>>c;s[i] = c-'0';}
    for(int i = 1;i<=n;i++) cin>>c[i];
    dfs(1);
    cout<<ans<<endl;
    return 0;
}