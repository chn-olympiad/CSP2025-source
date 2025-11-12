#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;
int t, n;
int diffa[MAXN], diffb[MAXN], diffc[MAXN];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
        for(int i=1, a, b, c; i<=n; i++) {
            cin >> a >> b >> c;
            int mx = max(a, max(b, c)), mn = min(a, min(b, c));
            if(a==mx) {
                cnt1 ++;
                ans += a;
                if(b==mn) {
                    diffa[cnt1] = a-c;
                } else {
                    diffa[cnt1] = a-b;
                }
            } else if(b==mx) {
                cnt2 ++;
                ans += b;
                if(a==mn) {
                    diffb[cnt2] = b-c;
                } else {
                    diffb[cnt2] = b-a;
                }
            } else {
                cnt3 ++;
                ans += c;
                if(a==mn) {
                    diffc[cnt3] = c-b;
                } else {
                    diffc[cnt3] = c-a;
                }
            }
        }
        if(cnt1>n/2) {
            sort(diffa+1, diffa+1+cnt1);
            for(int i=1; i<=cnt1-n/2; i++) {
                ans -= diffa[i];
            }
        } else if(cnt2>n/2) {
            sort(diffb+1, diffb+1+cnt2);
            for(int i=1; i<=cnt2-n/2; i++) {
                ans -= diffb[i];
            }
        } else if(cnt3>n/2) {
            sort(diffc+1, diffc+1+cnt3);
            for(int i=1; i<=cnt3-n/2; i++) {
                ans -= diffc[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
