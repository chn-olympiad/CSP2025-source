#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
struct node{
    int val1, val2, val3;
    int det;
    friend bool operator<(const node &a, const node &b) {
        return a.det < b.det;
    }
};
vector<node> q1, q2, q3;
void solve() {
    q1.clear(), q2.clear(), q3.clear();
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int a, b, c;
        node inp; cin >> a >> b >> c;
        inp.val1 = a, inp.val2 = b, inp.val3 = c;

        bool flag = 0;
        if (a >= b && a >= c && flag == 0) {
            inp.det = min(a - b, a - c);
            q1.push_back(inp), ans += a;
            flag = 1;
        }
        if (b >= a && b >= c && flag == 0) {
            inp.det = min(b - a, b - c);
            q2.push_back(inp), ans += b;
            flag = 1;
        }
        if (c >= a && c >= b && flag == 0) {
            inp.det = min(c - a, c - b);
            q3.push_back(inp), ans += c;
            flag = 1;
        }
    }
    if (!q1.empty())
    if (q1.size() > n / 2) {
        sort(q1.begin(), q1.end());
        for (int i = 0; i < q1.size() - n / 2; i ++)
            ans -= q1[i].det;
    }
    if (!q2.empty())
    if (q2.size() > n / 2) {
        sort(q2.begin(), q2.end());
        for (int i = 0; i < q2.size() - n / 2; i ++)
            ans -= q2[i].det;
    }
    if (!q3.empty())
    if (q3.size() > n / 2) {
        sort(q3.begin(), q3.end());
        for (int i = 0; i < q3.size() - n / 2; i ++)
            ans -= q3[i].det;
    }
    cout << ans << '\n';
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    // double st = clock();
    int t; cin >> t;
    while(t --)
        solve();
    // printf("%lfus\n", clock() - st);
    return 0;
}