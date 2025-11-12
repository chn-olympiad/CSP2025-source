#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
const int MAXN = 5e5 + 5;
int n, k, arr[MAXN], prefix[MAXN], ans;
struct qujian {
    int left, right;
};
vector<qujian> q;
bool cmp(qujian first, qujian second) {
    if (first.right == second.right) {
        return first.left > second.left;
    }
    else {
        return first.right < second.right;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] ^ arr[i];
        for (int j = 1; j <= i; j++) {
            int now = prefix[i] ^ prefix[j - 1];
            if (now == k) {
                q.push_back((qujian){j, i});
            }
        }
    }
    sort(q.begin(), q.end(), cmp);
    int last = -1;
    for (qujian& i : q) {
        if (i.left > last) {
            ans++;
            last = i.right;
        }
    }
    cout << ans << endl;
    return 0;
}
