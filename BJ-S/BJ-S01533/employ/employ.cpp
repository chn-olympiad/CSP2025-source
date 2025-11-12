#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m;
int s[N];
int c[N];
int p[N];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        s[i] = (ch - '0' == 1) ? 0 : 1;
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) s[i] += s[i - 1];
    for (int i = 1; i <= n; i++) p[i] = i;
    int res = 0;
    do {
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            if (c[p[i]] < s[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) res++;
    } while (next_permutation(p + 1, p + n + 1));
    cout << res;

    return 0;
}
