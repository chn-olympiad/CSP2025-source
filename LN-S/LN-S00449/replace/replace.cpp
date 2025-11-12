#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = a; i <= b; ++i)
#define rep_(i, a, b) for(register int i = a; i >= b;  --i)
typedef long long ll;
typedef unsigned long long ull;
namespace Kx {
    constexpr int N = 5000005;
    ll n, q;
    string s1, s2, t1, t2;
    map<string, ull> mp;
    map<string, string> mp1;
    ull hum[N];
    const ull B = 131;
    inline ull Pow(ull a, ull b) {
        ull res = 1ull;
        while(b) {
            if(b & 1ull) {
                res *= a;
            }
            a *= a;
            b >>= 1ull;
        }
        return res;
    }
    void main() { 
        freopen("replace.in", "r", stdin);
        freopen("replace.out", "w", stdout);
        ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cin >> n >> q;
        rep(i, 1, n) {
            cin >> s1 >> s2;
            mp1[s1] = s2;
            ull h1 = 0, h2 = 0;
            rep(i, 0, (int)s1.size() - 1) {
                h1 = h1 * B + s1[i] - 'a' + 1;
            }
            rep(i, 0, (int)s2.size() - 1) {
                h2 = h2 * B + s2[i] - 'a' + 1;
            }
            mp[s1] = h1;
            mp[s2] = h2;
        }
        while(q--) {
            ll ans = 0;
            cin >> t1 >> t2;
            ull target = 0, region = 0;
            rep(i, 1, (int)t1.size() - 1) {
                hum[i] = 0;
            }
            hum[0] = t1[0] - 'a' + 1;
            rep(i, 1, (int)t1.size() - 1) {
                hum[i] = hum[i - 1] * B + t1[i] - 'a' + 1;
            }
            region = hum[(int)t1.size() - 1];
            rep(i, 0, (int)t2.size() - 1) {
                target = target * B + t2[i] - 'a' + 1;
            }
            rep(i, 0, t1.size()) {
                for(const pair<string, string> c : mp1) {
                    ull from = mp[c.first], to = mp[c.second];
                    int len = c.first.size();
                    ull now = region;
                    if(i + 1 == len) {
                        ull delta = hum[i];
                        if(delta == from) {
                            now -= from * Pow(B, (int)(t1.size()) - i - 1);
                            now += to * Pow(B, (int)(t1.size()) - i - 1); 
                        }
                        if(now == target) {
                            ++ans;
                        }
                    }
                    else if(i + 1 > len) {
                        ull delta = hum[i] - hum[i - len] * pow(B, len);
                        if(delta == from) {
                            now -= from * Pow(B, (int)(t1.size()) - i - 1);
                            now += to * Pow(B, (int)(t1.size()) - i - 1); 
                        }
                        if(now == target) {
                            ++ans;
                        }
                    }
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