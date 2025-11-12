#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int m1, m2, m3;
    bool operator<(const node& b) const{
        return m1 - m2 > b.m1 - b.m2;
    }
} a[200005], b[200005], c[200005];

int n, ans, cnt1, cnt2, cnt3;

void solve(){
    cin >> n;
    ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if (max(max(x, y), z) == x){
            cnt1++;
            a[cnt1].m1 = x, a[cnt1].m2 = max(y, z), a[cnt1].m3 = min(y, z);
            ans += x;
        }
        else if (max(max(x, y), z) == y){
            cnt2++;
            b[cnt2].m1 = y, b[cnt2].m2 = max(x, z), b[cnt2].m3 = min(x, z);
            ans += y;
        }
        else {
            cnt3++;
            c[cnt3].m1 = z, c[cnt3].m2 = max(x, y), c[cnt3].m3 = min(x, y);
            ans += z;
        }
    }
    if (cnt1 > n / 2){
        sort(a + 1, a + cnt1 + 1);
        while (cnt1 > n / 2){
            ans -= a[cnt1].m1 - a[cnt1].m2;
            cnt1--;
        }
    }
    if (cnt2 > n / 2){
        sort(b + 1, b + cnt2 + 1);
        while (cnt2 > n / 2){
            ans -= b[cnt2].m1 - b[cnt2].m2;
            cnt2--;
        }
    }
    if (cnt3 > n / 2){
        sort(c + 1, c + cnt3 + 1);
        while (cnt3 > n / 2){
            ans -= c[cnt3].m1 - c[cnt3].m2;
            cnt3--;
        }
    }
    cout << ans << endl;
}

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
