#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int N = 5e5 + 5;
int xorSum[N];
int n, k;

struct Node {
    int l, r;
    bool operator<(const Node &other) const {
        return r == other.r ? l > other.l : r > other.r;
    }
};

priority_queue<Node> pq;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        xorSum[i] = xorSum[i - 1] ^ a;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if ((xorSum[j] ^ xorSum[i - 1]) == k) {
                pq.push({i, j});
            }
        }
    }

    int ans = 0, last = 0;;
    while (!pq.empty()) {
        Node t = pq.top(); pq.pop();
        if (t.l > last) {
            ans++;
            last = t.r;
        }
    }

    cout << ans;

    return 0;
}
