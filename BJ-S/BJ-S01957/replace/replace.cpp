#include <iostream>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
#define re register
typedef long long ll;
const int maxn = 5e6 + 10;
const int maxm = 2e5 + 10;
const int B = 13331;
const int P = 1222827239;
int n, m, q, id;
char s[maxn], t[maxn];
unordered_map<int, int> mp;
vector<pair<int, int> > e[maxm];
unordered_set<int> s1, s2;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (re int i = 1; i <= n; i++) {
        cin >> s + 1 >> t + 1; m = strlen(s + 1);
        int l = -1; for (int j = 1; j <= m; j++) if (s[j] != t[j]) {l = j; break;}
        if (l == -1) continue; int r;
        for (re int j = m; j >= 1; j--) if (s[j] != t[j]) {r = j; break;}
        int val = 0;
        for (re int j = l; j <= r; j++) val = ((ll)val * B + s[j]) % P, val = ((ll)val * B + t[j]) % P;
        if (mp.find(val) == mp.end()) mp[val] = ++id; int cid = mp[val];
        int val1 = 0, val2 = 0;
        for (re int j = l - 1; j >= 1; j--) val1 = ((ll)val1 * B + s[j]) % P;
        for (re int j = r + 1; j <= m; j++) val2 = ((ll)val2 * B + s[j]) % P;
        e[cid].emplace_back(val1, val2);
    }
    while (q--) {
        cin >> s + 1 >> t + 1; m = strlen(s + 1);
        if (m != strlen(t + 1)) {cout << "0\n"; continue;} int l, r;
        for (re int i = 1; i <= m; i++) if (s[i] != t[i]) {l = i; break;}
        for (re int i = m; i >= 1; i--) if (s[i] != t[i]) {r = i; break;} int val = 0;
        for (re int j = l; j <= r; j++) val = ((ll)val * B + s[j]) % P, val = ((ll)val * B + t[j]) % P;
        if (mp.find(val) == mp.end()) {cout << "0\n"; continue;}
        s1.clear(); s2.clear(); s1.insert(0); s2.insert(0); int val1 = 0, val2 = 0, ans = 0;
        for (re int j = l - 1; j >= 1; j--) val1 = ((ll)val1 * B + s[j]) % P, s1.insert(val1);
        for (re int j = r + 1; j <= m; j++) val2 = ((ll)val2 * B + s[j]) % P, s2.insert(val2);
        int cid = mp[val]; for (auto [x, y] : e[cid]) if (s1.count(x) && s2.count(y)) ++ans;
        cout << ans << '\n';
    }
    return 0;
}