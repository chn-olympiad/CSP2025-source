#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, t, maxn, ans;

struct member{
    int a, b, c, in;
}mem[N];

int dfs(int i, int a, int b, int c) {
    if (i > n) return 0;
    int num = 0;
    if (a < maxn) {
        num = max(num, dfs(i+1, a+1, b, c) + mem[i].a);
    }
    if (b < maxn) {
        num = max(num, dfs(i+1, a, b+1, c) + mem[i].b);
    }
    if (c < maxn) {
        num = max(num, dfs(i+1, a, b, c+1) + mem[i].c);
    }
    return num;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> mem[i].a >> mem[i].b >> mem[i].c;
            mem[i].in = 0;
        }
        maxn = n/2;
        cout << dfs(1, 0, 0, 0) << '\n';

    }

    return 0;
}
