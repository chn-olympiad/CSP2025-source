#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;

struct node {
    int a, b, c;
};
int n, ans = 0;

inline void dfs(vector<node>& a, int idx = 0, int sum = 0, int cnt_a = 0, int cnt_b = 0, int cnt_c = 0) {
    if (idx == n) {
        ans = max(ans, sum);
        return;
    }
    if (cnt_a < n / 2) {
        dfs(a, idx + 1, sum + a[idx].a, cnt_a + 1, cnt_b, cnt_c);
    }
    if (cnt_b < n / 2) {
        dfs(a, idx + 1, sum + a[idx].b, cnt_a, cnt_b + 1, cnt_c);
    }
    if (cnt_c < n / 2) {
        dfs(a, idx + 1, sum + a[idx].c, cnt_a, cnt_b, cnt_c + 1);
    }
    return;
}

inline int SP0(vector<node>& a) {
    sort(a.begin(), a.end(), [](node x, node y) {
        return x.a > y.a;
    });
    int sum = 0;
    for (int i = 0; i < n / 2; i++) {
        sum += a[i].a;
    }
    return sum;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(nullptr); cout.tie(nullptr);

    int times;
    cin >> times;
    while (times--) {
        cin >> n;
        vector<node> a(n);
        bool SP_b = true, SP_c = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i].a >> a[i].b >> a[i].c;
            if (a[i].b != 0) {
                SP_b = false;
            }
            if (a[i].c != 0) {
                SP_c = false;
            }
        }
        if (SP_b && SP_c) {
            cout << SP0(a) << endl;
            return 0;
        }
        ans = 0; dfs(a);
        cout << ans << endl;
    }
    return 0;
}
