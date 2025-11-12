#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct Node {
    int val, idx;
}a[N], b[N], c[N];
bool cmp(Node x, Node y) {
    return x.val > y.val;
}
int n, sum[4], num[7];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); 

    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        sort(a + 1, a + 1 + n, cmp);
        sort(b + 1, b + 1 + n, cmp);
        sort(c + 1, c + 1 + n, cmp);
        int x = 0, y = 0, z = 0, cnt = 0, ans = 0;
        sum = {0, 0, 0, 0};
        for (cnt <= n) {
            num[0] = 0, num[1] = a[x], num[2] = b[y], num[3] = c[z];
            num[4] = a[x + 1], num[5] = b[y + 1], num[4] = c[z + 1];
            int maxn = 0, pos1 = 0, pos2 = 0;
            for (int i = 1; i <= 3; i++) {
                if (sum[i] >= n / 2) continue;
                sum[i]++;
                for (int j = 4; j <= 6; j++) {
                    if (sum[j % 3] >= n / 2) continue;
                    if (num[i] + num[j] > maxn) {
                        pos1 = i, pos2 = j % 3;
                        maxn = num[i] + num[j];
                    }
                }
                sum[i]--;
            }
            ans += maxn;
            sum[pos1]++, sum[pos2]++;
            if (pos1 == 1) x++;
            else if (pos1 == 2) y++;
            else if (pos1 == 3) z++:
            if (pos2 == 1) x++;
            else if (pos2 == 2) y++;
            else if (pos2 == 3) z++; 
        }
        cout << ans << endl;
    }
    return 0;
}