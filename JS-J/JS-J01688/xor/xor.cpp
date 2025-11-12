#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int n, k, ans; 
int a[N], dp[N];
struct node {
    int l, r;
};
vector <node> v;
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (k == 1) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) ans ++;
        }
        cout << ans << endl;
    } 
    else if (k == 0) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) ans++;
            else if(a[i] == 1 && a[i - 1] == 1) {
                ans++, a[i] = a[i - 1] = 0;
            }
        }
        cout << ans << endl;
    } 
    else {
        int x;
        for (int i = 1; i <= n; i++) {
            x = a[i];
            if (x == k) {
                v.emplace_back(node{i, i});
                continue;
            }
            for (int j = i + 1; j <= n; j++) {
                x = (x ^ a[j]);
                if (x == k) {
                    v.emplace_back(node{i, j});
                    break;
                }
            }
        }
        sort(v.begin(), v.end(), [&](node xx, node yy) {
            if (xx.r == yy.r) {
                return xx.l < yy.l;
            }
            else return xx.r < yy.r;
        });
        int lst = 0, vl = v.size();
        for (int i = 0; i < vl; i++) {
            //cout << v[i].l << " " << v[i].r << endl;
            for (int j = lst; j <= v[i].r; j++) {
                dp[j] = max(dp[lst], dp[j]);
            }
            dp[v[i].r] = max(dp[v[i].l - 1] + 1, dp[v[i].r]);
            ans = max(ans, dp[v[i].r]);
            lst = v[i].r;
            //cout << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}