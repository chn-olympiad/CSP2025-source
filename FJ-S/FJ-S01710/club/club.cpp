#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gets() {
    int input = getchar();
    ll ret = 0, neg = 1;
    while(input < '0' || input > '9') {
        if(input == '-') {
            neg = -1;
        }
        input = getchar();
    }
    while(input >= '0' && input <= '9') {
        ret = input - '0' + ret * 10;
        input = getchar();
    }
    return ret * neg;
}
void puts(ll output) {
    if(output < 0) {
        putchar('-');
        output = - output;
    }
    if(output > 9) {
        puts(output / 10);
    }
    putchar(char(output % 10 + '0'));
}
int t, n;
vector<ll> a, b, c;
ll ans;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t --) {
        ans = 0LL;
        a.clear();
        b.clear();
        c.clear();
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            ll x, y, z;
            cin >> x >> y >> z;
            if(x >= y && x >= z) {
                a.emplace_back(x - max(y, z));
                ans += x;
            } else if(y >= x && y >= z) {
                b.emplace_back(y - max(x, z));
                ans += y;
            } else {
                c.emplace_back(z - max(x, y));
                ans += z;
            }
        }
        int len = 0;
        len = (int)a.size() - n / 2;
        if(len > 0) {
            sort(a.begin(), a.end());
            for(int i = 0; i < len; i ++) {
                ans -= a[i];
            }
        }
        len = (int)b.size() - n / 2;
        if(len > 0) {
            sort(b.begin(), b.end());
            for(int i = 0; i < len; i ++) {
                ans -= b[i];
            }
        }
        len = (int)c.size() - n / 2;
        if(len > 0) {
            sort(c.begin(), c.end());
            for(int i = 0; i < len; i ++) {
                ans -= c[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
//g++ -g club.cpp -o c -std=c++14 -O2 -Wall -Wextra -Wconversion -Wshadow -fsanitize=address,undefined
