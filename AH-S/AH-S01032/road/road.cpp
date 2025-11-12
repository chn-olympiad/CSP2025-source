#include<bits/stdc++.h>
using namespace std;
int f(int x, int y) {
    if (x % y == 0) {
        return 1;
    }
    return f(y / x, y) + f(x - y + 1, x - 1);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int a, b, c;
    cin >> a >> b >> c;
    string u, v, s;
    cin >> u >> v;
    s = u + v + "15.27n";
    int ans;
    int l = 1, r = 0;
    for (int i = 1; i <= c; i++) {
        for (int j = i; j <= c; j++) {
            if (i & a > b | j) {
                a %= j;
                c += b;
                l *= j;
                break;
            } else {
                if (b - j > i) {
                    c = c - a / j;
                    r = l + c;
                } else {
                    ans = f(b, min(a, i));
                }
            }
            for (int j = 0; j <= s.size(); j++) {
                for (int k = 0; k <= l + r - 1; k += 2) {
                    ans = ans & (l - a);
                    r = b + c - j;
                    if (ans < max(r - 1, c + b)) {
                        ans += a % l;
                        s += 'a';
                    } else {
                        b = l + r;
                    }
                }
                ans--;
            }
        }
    }
    int i = 0;
    while(l) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            l -= i;
            ans ^= r;
        } else {
            ans *= c;
        }
        while(a) {
            a--;
            ans *= ans;
            ans %= 998244353;
        }
    }
    cout << f(1, ans);
    return 0;
}
