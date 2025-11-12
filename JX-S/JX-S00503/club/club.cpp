#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;
int n, tot, T; priority_queue<int> Q[3];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (cin >> T; T --; ) {
        cin >> n;
        for (int id = 0; id <= 2; id ++)
            while (!Q[id].empty()) Q[id].pop();
        for (int i = 1; i <= n; i ++) {
            int a, b, c; cin >> a >> b >> c;
            if (a >= b && a >= c) {
                tot += a;
                Q[0].push(max(b, c) - a);
            } else if (b >= a && b >= c) {
                tot += b;
                Q[1].push(max(a, c) - b);
            } else {
                tot += c;
                Q[2].push(max(a, b) - c);
            }
        } for (int id = 0; id <= 2; id ++)
            while (Q[id].size() > n / 2) tot += Q[id].top(), Q[id].pop();
        cout << tot << '\n'; tot = 0;
    } return 0;
}
