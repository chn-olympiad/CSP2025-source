#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
int n;
int ans;
int a[5005];
bool check(vector <int> &e) {
    int sum = 0, mx = 0;
    for (int i = 0; i < e.size(); i++) {
        sum += a[e[i]];
        mx = max(mx, a[e[i]]);
    }
    return sum > 2 * mx;
}
void f(int x, int d, vector <int> e) {
    if (d == 0) {
        if (check(e)) {
            ans++;
            ans %= mod;
        }
        return ;
    }
    for (int i = x + 1; i <= n; i++) {
        e.push_back(i);
        f(i, d - 1, e);
        e.pop_back();
    }
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector <int> e;
    for (int i = 3; i <= n; i++) {
        e.clear();
        f(0, i, e);
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
