/* I only used 52 minutes to finish the first 3 problems.
   But I used 87 minutes to get only 60pts in T4???
   Then I wasted 65 minutes to write an incorrect code?????
   Prediction: 100+100+[80,100]+[40,60] = [320, 360]
   AFO soon...
*/
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const unsigned long long P = 998244353;

ull n;
ull a[5005], pre[5005];
ull ans;
ull fact[5005], inv[5005];
ull cntt[5005];

ull quick_pow(ull a, ull b) {
    if(!b) return 1;
    ull res = quick_pow(a, b >> 1);
    res = res * res % P;
    if(b & 1) res = res * a % P;
    return res;
}

ull count(int x) {
    if(cntt[x]) return cntt[x];
    ull res = 0;
    for(int i = 0; i <= x; i++) {
        res = (res + (fact[x] * inv[x - i] % P * inv[i]) % P) % P;
    }
    cntt[x] = res;
    return res;
}

ull count1(int x) {
    ull res = 0;
    for(int i = 2; i <= x; i++) {
        res = (res + (fact[x] * inv[x - i] % P * inv[i]) % P) % P;
    }
    return res;
}

void dfs(int p, ull sum, int cnt, int s) {
    if(p == 0) return;
    int ss = s? s : p;
    if(cnt + p < 3 || pre[p] + sum <= 2 * a[s]) return;
    sum += a[p], cnt++;
    if(sum > 2 * a[ss] && cnt >= 3) {
        ans = (ans + count(p - 1)) % P;
    } else {
        dfs(p - 1, sum, cnt, ss);
    }
    dfs(p - 1, sum - a[p], cnt - 1, s);
}

void solve1() {
    for(int i = 1; i <= n; i++) {
        ans = (ans + count(n - i)) % P;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    ull maxa = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    if(maxa == 1) {
        solve1();
        cout << ans;
        return 0;
    }
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % P;
        inv[i] = quick_pow(fact[i], P - 2);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    dfs(n, 0, 0, 0);
    cout << ans;
    return 0;
}
