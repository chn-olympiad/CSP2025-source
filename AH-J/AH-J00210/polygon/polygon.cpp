#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n, a[5005], ans = 0;
ll A(ll x, ll y){
    ll cnt = 0;
    ll p = 1, q = 1;
    for(int i = 1;i <= x;i++){
        if(cnt == y)    break;
        p *= i, q *= (x-i+1);
        p %= mod, q %= mod;
        cnt++;
    }
    return q/p;
}
bool cmp(ll x, ll y){return x > y;}
bool vis[5005];
void DFS(int st, int k, ll now, int s){
    if(k == 0) {
        if(now > 2*a[st])
            ans++, ans %= mod;
        return ;
    }
    for(int i = s+1;i < n;i++){
        vis[i] = 1;
        DFS(st, k-1, now+a[i], i);
        vis[i] = 0;
    }

}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    bool flag = true;
    for(int i = 0;i < n;i++)   {
        cin >> a[i];
        if(a[i] != 1)   flag = false;
    }
    if(flag){
        for(int i = 3;i <= n;i++)
            ans += A(n, i), ans %= mod;
        cout << ans << '\n';
    }
    else{
		sort(a, a+n, cmp);
        for(int i = 0;i < n;i++){
            for(int k = 3;k <= n;k++){
                memset(vis, 0, sizeof(vis));
                vis[i] = 1;
                DFS(i, k-1, a[i], i);
                vis[i] = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
