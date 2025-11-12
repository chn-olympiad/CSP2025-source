#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5010, MOD = 998244353;
int n, ans, ans1;
int a[N],next[N];
bool flag;

bool check(int sum, int maxx){
    return sum > 2 * maxx;
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;

    if(n < 3){
        cout << "0\n";
        return 0;
    }

    int sum = 0, maxx = -0x3f3f3f3f3f3f3f3f;
    for(int i = 1;i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
        maxx = max(maxx, a[i]);
        if(a[i] != 1) flag = true;
    }

    if(check(sum, maxx)) ans++;

    if(!flag){
        cout << (((1 + (n - 4 + 1)) * (n - 4 + 1)) / 2) % MOD << "\n";
        return 0;
    }

    cout << ans % MOD << "\n";
    return 0;
}
