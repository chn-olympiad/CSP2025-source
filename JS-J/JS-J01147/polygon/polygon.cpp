#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
int n;
int a[maxn];
bool b[maxn];
long long ans = 0;
void dfs(int dep){
    if(dep == n + 1){
        int l = 0, maxx = -inf, sum = 0;
        for(int i = 1; i <= n; i++){
            if(!b[i])
                 continue;
            l++;
            maxx = max(maxx, a[i]);
            sum += a[i];
        }
        if(sum > 2 * maxx && l >= 3)
            ans++, ans = ans % mod;
        return ;
    }
    b[dep] = true;
    dfs(dep + 1);
    b[dep] = false;
    dfs(dep + 1);
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1);
    cout<<ans % mod;
    return 0;
}