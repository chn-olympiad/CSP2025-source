#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int c[N];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    bool flag = 1,flag2 = 1;
    int cnt = 0;
    for (int i=1;i<=n;++i) {
        cin >> c[i];
        if (c[i] != 1) flag = 0;
        if (c[i] != 1 && c[i]) flag2 = 0;
        if (c[i]) ++cnt;
    }
    if (flag) {
        cout << n / 2;
        return 0;
    }
    if (flag2) {
        if (k == 1) {
            cout << cnt;
            return 0;
        }
        int ans = 0;
        int last = 0;
        for (int i=1;i<=n;++i) {
            if (c[i] && last) ++ans,last = 0;
            else if (c[i] && !last) last = 1;
            else if (!c[i] && !last) ++ans;
        }
        cout << ans;
    }
    return 0;
}
