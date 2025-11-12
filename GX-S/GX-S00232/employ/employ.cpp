#include <iostream>
#include <algorithm>

using namespace std;

int n, m, c[600];
string hard;

int ans;

int p[600];
bool used[600];
void ddfs(int pos) {
    if (pos == n) {
        int total = 0;
        for (int i = 0;i < n;++i) {
            if (hard[i] == '1' && (i - total) < c[p[i]]) total++;
        }
        if (total >= m) {
            ans ++;
            ans %= 998244353;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            used[i] = true;
            p[pos] = i;
            ddfs(pos + 1);
            used[i] = false;
        }
    }
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> hard;
    for (int i = 0;i < n;++i) {
        cin >> c[i];
    }

    ddfs(0);

    printf("%d\n", ans);
}