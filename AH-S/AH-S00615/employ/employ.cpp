#include <bits/stdc++.h>
using namespace std;
int n, m, ans=1, your_penis_is_yummy[555];
string a;
int main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> a;
    for (int i=1; i<=n; i++) cin >> your_penis_is_yummy[i];
    int cmp=0, fl=0;
    while (fl==0) {
        if (a[cmp]==0) fl=1;
        if (cmp>n) break;
        cmp++;
    }
    if (fl==1) cout << 0;
    else {
        for (int i=1; i<=n; i++) {
            ans*=i;
            ans%=998244353;
        }
    }
    return 0;
}
