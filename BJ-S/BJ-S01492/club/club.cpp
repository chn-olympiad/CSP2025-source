# include <bits/stdc++.h>
using namespace std;
int t,n,aa,bb,cc;
struct node{
    int a, b, c, mx, sm;
};
bool cmpc (int a, int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        node a[114514];
        int b[114514];
        int mx = 0, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >>a[i].a >> a[i].b >>a[i].c;
            b[i] = a[i].a;
            a[i].sm = a[i].a+a[i].b+a[i].c;
            a[i].mx = max({a[i].a,a[i].b,a[i].c});
            mx = max(mx, a[i].c);
        }
        if (mx == 0) {
            //int dp[114514][3];
            //for (int i = 1; i <= n; ++i) {
            //    dp[i][1] = max(dp[i-1][1]+a[i], dp[i-1][2]+a[i]);
            //    dp[i][2] = max(dp[i-1][1]+a[i])
            //}
            sort(b+1, b+n+1, cmpc);
            for (int i = 1; i <= n/2; ++i) {
                ans += b[i];
            }
            cout <<ans <<endl;
        } else {
            aa=bb=cc=n/2;
            for (int i = 1; i <= n; ++i) {
                if (a[i].mx == a[i].a && aa) {
                    ans+=a[i].mx; aa--;
                }
                if (a[i].mx == a[i].b && bb) {
                    ans+=a[i].mx; bb--;
                }
                if (a[i].mx == a[i].c && cc) {
                    ans+=a[i].mx; cc--;
                }
                if (a[i].mx == a[i].a && !aa) {
                    if (a[i].b >= a[i].c) {
                        ans += a[i].b; bb--;
                    } else {
                        ans += a[i].c; cc--;
                    }
                }
                if (a[i].mx == a[i].b && !bb) {
                    if (a[i].a >= a[i].c) {
                        ans += a[i].a; aa--;
                    } else {
                        ans += a[i].c; cc--;
                    }
                }
                if (a[i].mx == a[i].c && !cc) {
                    if (a[i].a >= a[i].b) {
                        ans += a[i].a; aa--;
                    } else {
                        ans += a[i].b; bb--;
                    }
                }
            }
            cout << ans <<endl;
        }
    }

    return 0;
}
