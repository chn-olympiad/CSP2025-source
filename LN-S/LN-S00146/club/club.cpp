#include <bits/stdc++.h>

using namespace std;

struct str{
    int n1, n2, n3;
}a[100005];

bool cpp(str x, str y) {
    if (x.n1 == y.n1) {
        if (x.n2 == y.n2)
            return x.n3 > y.n3;
        return x.n2 > y.n2;
    }
    return x.n1 > y.n1;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].n1 >> a[i].n2 >> a[i].n3;
        }
        sort(a+1, a+1+n, cpp);
        int ans = 0, num1 = 0, num2 = 0, num3 = 0;
        if (n == 2) {
            ans = max(a[1].n1+a[2].n2, a[1].n1+a[2].n3);
            ans = max(ans, a[1].n2+a[2].n3);
            ans = max(ans, a[1].n3+a[2].n2);
            ans = max(ans, a[1].n3+a[2].n1);
            ans = max(ans, a[1].n2+a[2].n1);
            cout << ans << endl;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (a[i].n1 < a[i].n3 && a[i].n2 < a[i].n3) {
                if (num3 < n/2) {
                    num3++;
                    ans += a[i].n3;
                } else {
                    if (a[i].n1 < a[i].n2) {
                        num2++;
                        ans += a[i].n2;
                    } else {
                        num1;
                        ans += a[i].n1;
                    }
                }
            } else if (a[i].n1 < a[i].n2 && a[i].n3 < a[i].n2) {
                if (num2 < n/2) {
                    num2++;
                    ans += a[i].n2;
                } else {
                    if (a[i].n1 < a[i].n3) {
                        num3++;
                        ans += a[i].n3;
                    } else {
                        num1;
                        ans += a[i].n1;
                    }
                }
            } else {
                if (num1 < n/2) {
                    num1++;
                    ans += a[i].n1;
                } else {
                    if (a[i].n3 < a[i].n2) {
                        num2++;
                        ans += a[i].n2;
                    } else {
                        num3;
                        ans += a[i].n3;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
