#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 5010;
int n,a[N],mx = -1;
int y[N][N],b[N];
int ans;
//bool vis[N];
void dfs(int id,int sum){
    if(id == n + 1) return;
    if(sum > a[id]){
        b[id] += 1;
        b[id] %= mod;
    }
    dfs(id + 1,sum + a[id]);
    dfs(id + 1,sum);
}
int32_t main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    y[1][1] = 1;
    for(int i = 2;i <= 5000;++i){
        for(int j = 1;j <= i;++j){
            y[i][j] = y[i - 1][j] + y[i - 1][j - 1];
        }
    }
    scanf("%lld",&n);
    for(int i = 1;i <= n;++i){
        scanf("%lld",&a[i]);
        mx = max(mx,a[i]);
    }
    sort(a + 1,a + n + 1);
    if(mx == 1){
        int ans = 0;
        for(int i = 4;i <= n;i++){
            ans += y[n + 1][i + 1];
            ans %= mod;
        }
        printf("%lld",ans);
        return 0;
    }
    dfs(1,0);
    for(int i = 1;i <= n;++i){
        ans += b[i];
        ans %= mod;
    }
    printf("%lld",ans);
    return 0;
}
