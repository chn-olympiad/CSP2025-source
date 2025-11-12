#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = a; i <= b; ++i)
#define rep_(i, a, b) for(register int i = a; i >= b;  --i)
typedef long long ll;
namespace Kx {
    constexpr int N = 100005;
    ll n, ans, cnt1, cnt2, cnt3, tot;
    struct ls {
        ll a, b, c;
    }p[N], p1[N], p2[N], p3[N];
    inline bool cmp1(ls x, ls y) {
        return x.a - max(x.b, x.c) < y.a - max(y.b, y.c);
    }
    inline bool cmp2(ls x, ls y) {
        return x.b - max(x.a, x.c) < y.b - max(y.a, y.c);
    }
    inline bool cmp3(ls x, ls y) {
        return x.c - max(x.a, x.b) < y.c - max(y.a, y.b);
    }
    void main() {
        freopen("club.in", "r", stdin);
        freopen("club.out", "w", stdout);
        ios :: sync_with_stdio(0), cin.tie(0);
        int t; cin >> t;
        while(t--) {
            cin >> n;
            ans = tot = cnt1 = cnt2 = cnt3 = 0;
            rep(i, 1, n) {
                cin >> p[i].a >> p[i].b >> p[i].c;
                if(p[i].a > p[i].b && p[i].a > p[i].c) {
                    p1[++cnt1] = p[i];
                }
                else if(p[i].b > p[i].a && p[i].b > p[i].c) {
                    p2[++cnt2] = p[i];
                }
                else if(p[i].c > p[i].a && p[i].c > p[i].b) {
                    p3[++cnt3] = p[i];
                }
                ans += max({p[i].a, p[i].b, p[i].c});
            }
            if(cnt1 > n / 2) {
                sort(p1 + 1, p1 + cnt1 + 1, cmp1);
                rep(j, 1, cnt1 - n / 2) {
                    ans -= p1[j].a - max(p1[j].b, p1[j].c);
                }
            }
            else if(cnt2 > n / 2) {
                sort(p2 + 1, p2 + cnt2 + 1, cmp2);
                rep(j, 1, cnt2 - n / 2) {
                    ans -= p2[j].b - max(p2[j].a, p2[j].c);
                }
            }
            else if(cnt3 > n / 2) {
                sort(p3 + 1, p3 + cnt3 + 1, cmp3);
                rep(j, 1, cnt3 - n / 2) {
                    ans -= p3[j].c - max(p3[j].a, p3[j].b);
                }
            }
            cout << ans << '\n';
        }
    }
}
int main() {
    Kx :: main(); 
    return 0;
}