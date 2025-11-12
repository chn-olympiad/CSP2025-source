#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll t, n;
struct pst{
    ll one, two, th, sub1;
}a[100010];
struct st{
    ll val, s1, s2;
};
st ton1[100010], ton2[100010], ton3[100010];
bool cmp(st one, st two) {
    return one.s1 < two.s1;
}
ll loc[100010], loc2[100010];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        ll maxi = 0, max2 = 0, cc = 0, cc1 = 0, cc2 = 0, ans = 0;
        cin >> n;

        for(int i = 1; i <= n; i++) {
            cin >> a[i].one >> a[i].two >> a[i].th;
            if(a[i].one >= a[i].two) {
                loc[i] = 1;
                max2 = a[i].two;
                loc2[i] = 2;
            }
            else {
                loc[i] = 2;
                max2 = a[i].one;
                loc2[i] = 1;
            }
            maxi = max(a[i].one, a[i].two);
            if(maxi <= a[i].th) {
                loc2[i] = loc[i];
                loc[i] = 3;
                max2 = maxi;
                maxi = a[i].th;
            }
            a[i].sub1 = maxi - max2;
        }

        for(int i = 1; i <= n; i++) {
            if(loc[i] == 1) {
                ton1[++cc].val = a[i].one;
                ton1[cc].s1 = a[i].sub1;
                ans += a[i].one;
            }
            else if(loc[i] == 2) {
                ton2[++cc1].val = a[i].two;
                ton2[cc1].s1 = a[i].sub1;
                ans += a[i].two;
            }
            else {
                ton3[++cc2].val = a[i].th;
                ton3[cc2].s1 = a[i].sub1;
                ans += a[i].th;
            }
        }
        sort(ton1 + 1, ton1 + 1 + cc, cmp);
        sort(ton2 + 1, ton2 + 1 + cc1, cmp);
        sort(ton3 + 1, ton3 + 1 + cc2, cmp);
        if(cc > n / 2) {
            for(int j = 1; cc - j >= n / 2; j++) {
                ans -= ton1[j].s1;
            }
        }
        if(cc1 > n / 2) {
            for(int j = 1; cc1 - j >= n / 2; j++) {
                ans -= ton2[j].s1;
            }
        }
        if(cc2 > n / 2) {
            for(int j = 1; cc2 - j >= n / 2; j++) {
                ans -= ton3[j].s1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
