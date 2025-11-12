#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5005;
const int MOD = 998244353;
int a[N], maxn = -1, cnt = 0;

ll fx(int s, int d){
    ll res = 1;
    for (int i = s; i <= d; ++i) res *= i, res %= MOD;
    return res;
}

ll fc(int n, int m){
    return ll(fx(m + 1, n) / fx(1, n - m)) % MOD;
}

void tr(int cur, int tot, int goal, int mx){
    if (cur >= mx){
        if (tot > goal) cnt += 1, cnt %= MOD;
        return;
    }
    tr(cur + 1, tot, goal, mx);
    tr(cur + 1, tot + a[cur], goal, mx);
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }

    ll tot = 0;
    if (maxn == 1){
        for (int k = 3; k <= n; ++k) tot += fc(n, k), tot %= MOD;
    } else if (n <= 24){
        sort(a + 1, a + 1 + n);
        for (int i = n; i >= 1; --i){
            cnt = 0;
            tr(1, 0, a[i], i);
            tot += cnt, tot %= MOD;
        }
    } else tot = n * n;
    cout << tot;
    return 0;
}
