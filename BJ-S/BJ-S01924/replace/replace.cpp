#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN = 2e5 + 5, base = 499, MAXL = 5e6 + 5;
ll n, q;
vector <ull> h[MAXN][2], t[MAXN][2];
ull bp[MAXL];
string s[MAXN][2];
ll ans[MAXN];
vector <ull> hash_init(string str) {
    vector <ull> ans;
    ans.push_back(0);
    for(int i = 0; i < str.size(); i++) {
        ans.push_back(ans[ans.size() - 1] * base + str[i]);
    }
    return ans;
}
void pow_init() {
    bp[0] = 1;
    for(int i = 1; i <= 5e6 + 2; i++)
        bp[i] = bp[i - 1] * base;
    return ;
}
ull gethash(vector <ull> H, ll l, ll r) {
    return H[r] - H[l - 1] * bp[r - l + 1];
}
ll getlen(ll x, ll Maxlen) {
    ll l = 0, r = Maxlen, ans = 0;
    while(l <= r) {
        ll mid = l + r >> 1;
        if(gethash(h[x][0], 1, mid) == gethash(h[x][1], 1, mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    return ans;
}
ll getlent(ll x, ll Maxlen) {
    ll l = 0, r = Maxlen, ans = 0;
    while(l <= r) {
        ll mid = l + r >> 1;
        if(gethash(t[x][0], 1, mid) == gethash(t[x][1], 1, mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    return ans;
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    cin >> n >> q;
    pow_init();
    for(int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        h[i][0] = hash_init(s[i][0]);
        h[i][1] = hash_init(s[i][1]);
        ll x = getlen(i, s[i][0].size());
        // cout << i << " : " << x << " " << h[i][0][h[i][0].size() - 1] << " " << h[i][1][h[i][1].size() - 1] << "\n";
        // mp[{h[i][0][h[i][0].size() - 1], h[i][1][h[i][1].size() - 1]}]++;
    }
    ll pwpw = 0;
    while(q--) {
        string x, y;
        pwpw++;
        cin >> x >> y;
        if(x.size() != y.size()) {
            cout << 0 << "\n";
            continue;
        }
        ll st, ed;
        for(int j = 0; j < x.size(); j++) 
            if(x[j] != y[j]) {
                st = j;
                break;
            }
        for(int j = x.size() - 1; j >= 0; j--) 
            if(x[j] != y[j]) {
                ed = j;
                break;
            }
        t[pwpw][0] = hash_init(x);
        t[pwpw][1] = hash_init(y);
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i][0].size() < ed - st + 1)
                continue;
            for(int j = 0; j + s[i][0].size() - 1 < x.size(); j++) {
                if(j > st || j + s[i][0].size() - 1 < ed)
                    continue;
                // cout << j << " : " << gethash(t[pwpw][0], j + 1, j + s[i][0].size()) << " " << gethash(h[i][0], 1, s[i][0].size()) << "\n";
                ans += gethash(t[pwpw][0], j + 1, j + s[i][0].size()) == h[i][0][h[i][0].size() - 1]
                 && gethash(t[pwpw][1], j + 1, j + s[i][1].size()) == h[i][1][h[i][1].size() - 1];
            }
        }
        cout << ans << "\n";
        //  << " " << (ll)('x') << " " << (ll)('a') << " " << (ll)('b') << " " << (ll)('c') << " " << "\n";
    }
    return 0;
}