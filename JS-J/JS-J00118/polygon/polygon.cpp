#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//zheng nan ze fan yi
const int N = 5010, MOD = 998244353;
int n;
ll a[N], pre3[N], pre2[N], pre1[N], dp2[N], dp[N];
void add(int op, int x, int c) {
    if(op == 1) {
        for(int i = x;i < N;i += i & -i) {
            pre1[i] += c;
            pre1[i] %= MOD;
        }
    }else if(op == 2) {
        for(int i = x;i < N;i += i & -i) {
            pre2[i] += c;
            pre2[i] %= MOD;
        }
    }else {
        for(int i = x;i < N;i += i & -i) {
            pre3[i] += c;
            pre3[i] %= MOD;
        }
    }
}
ll sum(int op, int x) {
    ll ret = 0;
    if(op == 1) {
        for(int i = x;i > 0;i -= i & -i) {
            ret += pre1[i];
            ret %= MOD;
        }
    }else if(op == 2) {
        for(int i = x;i > 0;i -= i & -i) {
            ret += pre2[i];
            ret %= MOD;
        }
    }else {
        for(int i = x;i > 0;i -= i & -i) {
            ret += pre3[i];
            ret %= MOD;
        }
    }
    return ret % MOD;
}
ll qp(int n, int a) {
    ll ret = 1;
    while(a) {
        if(a % 2 == 1) {
            ret *= n;
            ret %= MOD;
        }
        a /= 2;
        n = n * n;
        n %= MOD;
    }
    return ret;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll ans = qp(2, n) + MOD;
    //cout << ans << "\n\n";
    for(int i = 1;i <= n;i ++) {
        ans -= sum(3, a[i]);
        ans %= MOD;
     //   cout << sum(3, a[i]) << " " << sum(2, a[i]) << "\n";
        ans -= sum(2, a[i]);
        ans %= MOD;
        ans -= sum(1, N - 1);
        ans %= MOD;
        for(int j = N - a[i];j >= 0;j --) {
            if(dp2[j] != 0) {
                add(3, j + a[i], dp2[j]);
                dp2[j + a[i]] += dp2[j];
                dp2[j + a[i]] %= MOD;
            }
        }
        for(int j = N - a[i];j >= 0;j --) {
            if(dp[j] != 0) {
                add(2, j + a[i], dp[j]);
                dp2[j + a[i]] += dp[j];
                dp2[j + a[i]] %= MOD;
            }
        }
        dp[a[i]] ++;
        dp[a[i]] %= MOD;
        add(1, a[i], 1);
    }
    cout << (ans - n - 1 + MOD + MOD) % MOD;
    return 0;
}
