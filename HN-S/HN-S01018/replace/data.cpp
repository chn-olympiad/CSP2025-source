#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define file(s) freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
using namespace std;
template <typename T> inline bool ckmin(T &x, T y) {return (y < x) && (x = y, true);}
template <typename T> inline bool ckmax(T &x, T y) {return (x < y) && (x = y, true);}
mt19937 rnd(random_device{}());
char s[2500005];
inline void gen(int n)
{
    while (n --) cout << (char)('a' + rnd() % 26);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << "1 1\n";
    gen(2500000), cout << ' ', gen(2500000), cout << '\n';
    for (int i = 1; i <= 2500000; ++ i) s[i] = 'a' + rnd() % 26;
    cout << (s + 1) << ' ';
    if (s[1] == 'a') s[1] = 'b';
    else s[1] = 'a';
    cout << (s + 1);
    return 0;
}