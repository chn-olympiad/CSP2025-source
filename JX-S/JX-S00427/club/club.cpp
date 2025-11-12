#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int t, n, ans;

struct Node{
    int b1;
    int b2;
    int b3;
}arr[N];

void dfs(int i, int bm1, int bm2, int bm3, int sum) {
    if (i > n) {
        ans = max(ans, sum);
        return;
    }
    if (bm1 < n / 2) {
        dfs(i + 1, bm1 + 1, bm2, bm3, sum + arr[i].b1);
    }
    if (bm2 < n / 2) {
        dfs(i + 1, bm1, bm2 + 1, bm3, sum + arr[i].b2);
    }
    if (bm3 < n / 2) {
        dfs(i + 1, bm1, bm2, bm3 + 1, sum + arr[i].b3);
    }
}

bool cmp(Node a, Node b) {
    return a.b1 > b.b1;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        bool f1 = true, f2 = true;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].b1 >> arr[i].b2 >> arr[i].b3;
            if (arr[i].b2 != 0) f1 = false;
            if (arr[i].b3 != 0) f2 = false;
        }

        if (f1 && f2) {
            sort(arr + 1, arr + 1 + n, cmp);
            int sum = 0;
            for (int i = 1; i <= n / 2; i++) {
                sum += arr[i].b1;
            }
            cout << sum << '\n';
            continue;
        }

        ans = 0;
        dfs(1, 0, 0, 0, 0);

        cout << ans << '\n';
    }
    return 0;
}
