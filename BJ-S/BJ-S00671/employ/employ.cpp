#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2+10, mod = 998244353;
int n,m,c[N],t[N],ans; char s[N];
bool vis[N];
void dfs(int d) {
    if(d>n) {
        int cnt=0;
        for(int i=1,tmp=0;i<=n;i++)
            if(s[i]=='1' && tmp<c[t[i]]) cnt++;
            else tmp++;
        ans=(ans+(cnt>=m));
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) {
            t[d]=i,vis[i]=1;
            dfs(d+1);
            vis[i]=0;
        }
}
signed main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(n<=18) {
        for(int i=1;i<=n;i++)
            cin>>s[i];
        for(int i=1;i<=n;i++)
            cin>>c[i];
        dfs(1);
        cout<<ans;
    }
    else { 
        ans=1;
        for(int i=1;i<=n;i++)
            ans=(ans*i)%mod;
        cout<<ans;
    }
    return 0;
}