#include <bits/stdc++.h>
using namespace std;

int q[100001];
struct qu{
    int l, r;
} solve[1000001];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        q[i] = q[i - 1] ^ x;
    }
    unordered_set<int> pro;
    pro.insert(0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (pro.count(k ^ q[i])) {
            pro.clear();
            pro.insert(q[i]);
            ans++;
        }
        else {
            pro.insert(q[i]);
        }
    }

    cout << ans;
}
