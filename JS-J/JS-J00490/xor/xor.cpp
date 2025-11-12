#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, k, ans = 0;
int a[500005];
bool chk(int A, int B) {
    int res = a[A];
    if (A == B)
        return res == k;
    for (int i = A+1; i <= B; i++) {
        res ^= a[i];
    }
    return res == k;
}
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int qt=0,cntone=0,cntzero=0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //if (a[i] == k) qt++;
        if (a[i] == 1) cntone++;
        if (a[i] == 0) cntzero++;
    }
    ans=qt;
    if (cntone == n && k == 0) {
        cout << n / 2 << endl;
        return 0;
    }
    if (cntone + cntzero == n && k <= 1) {
        ans = 0;
        if (k == 0) {
            for (int i = 1; i <= n; i++) {
                if (a[i] == a[i + 1] && i != n) ans++, i += 1;
            }
            ans = max(ans, cntzero);
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (a[i] != a[i + 1] && i != n) ans++, i += 1;
            }
            ans = max(ans, cntone);
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (chk(i,j) && i + j != n + 1) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
