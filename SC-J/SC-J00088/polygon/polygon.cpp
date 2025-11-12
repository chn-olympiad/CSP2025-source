#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,ans,a[5005];
bool flag,vis[5005];
void dfs(int h,int sum,int mx,int j){
    if(h >= 3 && mx * 2 < sum) ans = (ans + 1) % mod;
    if(h == n) return;
    for(int i = j + 1;i <= n;i++)
        if(!vis[i]){
            vis[i] = 1;
            dfs(h + 1,sum + a[i],max(mx,a[i]),i);
            vis[i] = 0;
        }
}
int C(int u,int d){
    int cnt = 1,j = 2;
    for(int i = d - u + 1;i <= d;i++){
        int k = i;
        while(j <= u && k % j == 0) k /= j,j++;
        cnt = cnt * k % mod;
    }
    return cnt;

}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
        if(a[i] != 1) flag = 1;
    }
    if(flag) dfs(0,0,0,0);
    else for(int i = 3;i <= n;i++) ans = (ans + C(i,n)) % mod;
    cout << ans;
    return 0;
}
