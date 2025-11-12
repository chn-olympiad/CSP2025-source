#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i, x, y) for (int i = (x); i <= (y); i ++)
const int N = 1e5 + 6;
int T, n, a[4][N], dp[2][N], ans, f = 1;
void rd(int& res){
    char c; int f = 0; res = 0;
    do c = getchar(), f |= c == '-'; while (c < '0' || c > '9');
    do res = (res << 3) + (res << 1) + c - 48, c = getchar();
        while (c >= '0' && c <= '9');
    res *= f ? -1 : 1;
}
void dfs(int id, int x, int y, int z, int s){
    ans = max(ans, s);
    if (id > n) return;
    if (x + 1 <= n / 2) dfs(id + 1, x + 1, y, z, s + a[1][id]);
    if (y + 1 <= n / 2) dfs(id + 1, x, y + 1, z, s + a[2][id]);
    if (z + 1 <= n / 2) dfs(id + 1, x, y, z + 1, s + a[3][id]);
}
int spe(){
    int ans = 0;
    fr(i, 1, n) ans += max(max(a[1][i], a[2][i]), a[3][i]);
    return ans;
}
int just_do_it(){
    int ans = 0;
    sort(a[1] + 1, a[1] + n + 1);
    fr(i, n / 2 + n % 2 + 1, n) ans += a[1][i];
    return ans;
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    rd(T);
    while (T --){
        rd(n), ans = 0;
        fr(i, 1, n) rd(a[1][i]), rd(a[2][i]), rd(a[3][i]), f &= !a[3][i] && !a[2][i];
        if (n <= 32) dfs(1, 0, 0, 0, 0), cout << ans << "\n";
        else if (!f) cout << spe() << "\n";
        else cout << just_do_it() << "\n";
    }
    return 0;
}