#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int value, type;
}a[5];
const int N = 1e5 + 5;
bool cmp (const Node&x, const Node&y) {
    return x.value < y.value;
}
int loss1[N], loss2[N], loss3[N];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        int num[5]={0};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 3; ++j) {
                cin >> a[j].value;
                a[j].type = j;
            }
            sort(a + 1, a + 1 + 3, cmp);
            ans += a[3].value;
            ++num[a[3].type];
            if (a[3].type == 1) loss1[num[1]] = a[3].value - a[2].value;
            if (a[3].type == 2) loss2[num[2]] = a[3].value - a[2].value;
            if (a[3].type == 3) loss3[num[3]] = a[3].value - a[2].value;
        }
        if (num[1] > n / 2) {
            sort(loss1 + 1, loss1 + 1 + num[1]);
            for (int i = 1; num[1] - i >= n / 2; ++i) ans -= loss1[i];
        }
        if (num[2] > n / 2) {
            sort(loss2 + 1, loss2 + 1 + num[2]);
            int cnt = 0;
            for (int i = 1; num[2] - i >= n / 2; ++i) ans -= loss2[i], ++cnt;
        }
        if (num[3] > n / 2) {
            sort(loss3 + 1, loss3 + 1 + num[3]);
            for (int i = 1; num[3] - i >= n / 2; ++i) ans -= loss3[i];
        }
        cout << ans << "\n";
    }

    return 0;
}
