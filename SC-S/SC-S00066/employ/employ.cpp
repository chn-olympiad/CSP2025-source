#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int mod = 998244353;
int n,m,ct,ans,c[N],a[N];
bool vis[N];
string s;
void dfs(int h){
    if(h == n){
        int cnt = 0,shib = 0;;
        for(int i = 1;i <= n;i++)
            if(shib < c[a[i]] && s[i-1] == '1') cnt++;
            else shib++;
        if(cnt >= m) ans = (ans + 1) % mod;
        return;
    }
    for(int i = 1;i <= n;i++)
        if(!vis[i]){
            vis[i] = 1;
            a[h+1] = i;
            dfs(h + 1);
            vis[i] = 0;
        }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld %lld\n",&n,&m);cin >> s;
    for(int i = 1;i <= n;i++) scanf("%lld",&c[i]);
    for(int i = 0;i < s.length();i++)
        if(s[i] == '1') ct++;
    if(m > ct) cout << 0;
    else dfs(0),cout << ans;
    return 0;
}
