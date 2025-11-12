#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int a[5010],fac[5010],ivfac[5010],n;
bool vis[5010];
int qmi(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
void init(){
    fac[0] = ivfac[0] = 1;
    for(int i = 1;i <= 5000;i++){
        fac[i] = (fac[i - 1] * i) % p;
        ivfac[i] = (ivfac[i - 1] * qmi(i,p - 2)) % p;
    }
}
int ans = 0;
void dfs(int sum,int mx,int lst){
    if(sum > mx * 2) ans++;
    for(int i = lst + 1;i <= n;i++){
        if(vis[i]) continue;
        int s = sum + a[i],x = max(mx,a[i]);
        vis[i] = 1;
        dfs(s,x,i);
        vis[i] = 0;
    }
    return;
}
void bfs(){
    for(int i = 1;i <= n - 2;i++){
        for(int j = i + 1;j <= n - 1;j++){
            for(int k = j + 1;k <= n;k++){
                int s = a[i] + a[j] + a[k];
                int mx = max({a[i],a[j],a[k]});
                vis[i] = vis[j] = vis[k] = 1;
                dfs(s,mx,k);
                vis[i] = vis[j] = vis[k] = 0;
            }
        }
    }
    cout << ans << '\n';
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int ma = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        ma = max(ma,a[i]);
    }
    if(ma == 1){
        init();
        ans = 0;
        for(int i = 3;i <= n;i++){
            ans = ((((fac[n] * ivfac[i]) % p * ivfac[n - i]) % p) + ans) % p;
        }
        cout << ans << '\n';
        return 0;
    }
    bfs();
    return 0;
}