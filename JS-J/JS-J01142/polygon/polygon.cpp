#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll num = 0,sign = 1;char ch = ' ';
    while(ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1),ch = getchar();
    while(ch >= '0' && ch <= '9') num = (num << 3) + (num << 1) + ch - '0',ch = getchar();
    return sign == 1 ? num : -num;
}
const ll mod = 998244353;
ll n,a[5010],ans,a1,c[5010][5010];
void dfs(ll i,ll g,ll mx,ll sum){
    if(g >= 3 && sum > 2 * mx) ans = (ans + 1) % 998244353;
    if(i > n) return ;
    for(;i <= n;i++) dfs(i + 1,g + 1,max(mx,a[i]),sum + a[i]);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n = read();
    for(int i = 1;i <= n;i++){
        a[i] = read();
        if(a[i] == 1) a1++;
    }
    for(int i = 0;i <= n;i++){
        c[i][0] = 1;
        for(int j = 1;j < i;j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        c[i][i] = 1;
    }
    if(a1 == n){
        for(int i = 3;i <= n;i++) ans = (ans + c[n][i]) % mod;
        cout << ans << '\n';return 0;
    }
    dfs(1,0,0,0);cout << ans << '\n';
    return 0;
}
