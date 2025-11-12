#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define rep(_x,_y,_z) for(int _x=(_y); _x <= (_z); _x++)
#define rrep(_x,_y,_z) for(int _x=(_y); _x >= (_z); _x--)
#define fi first
#define se second
#define ull unsigned long long
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using namespace __gnu_pbds;

ull pwpwpw[5000005];
int ord[200005];
string a[200005], b[200005];
gp_hash_table<ull, int> mp;
ull hsh__1[5000005], hsh__2[5000005];

inline ull getw(int l, int r) {
    ull w1 = hsh__1[r] - hsh__1[l-1] * pwpwpw[r-l+1];
    ull w2 = hsh__2[r] - hsh__2[l-1] * pwpwpw[r-l+1];
    ull w = w1 * pwpwpw[r-l+1] * 97 + w2;
    return w;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    pwpwpw[0] = 1;
    rep(i, 1, 5000000) {
        pwpwpw[i] = pwpwpw[i-1] * 97;
    }
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> a[i] >> b[i];
        ord[i] = i;
    }
    sort(ord+1, ord+n+1, [](const int & x, const int & y) {
        return a[x].size() < a[y].size();
    });
    rep(k, 1, n) {
        int i = ord[k];
        int len = a[i].size();
        ull c1 = 0, c2 = 0, cnt = 0, w = 0;
        rep(j, 0, len-1) {
            c1 = c1 * 97 + a[i][j] - 'a' + 1;
            c2 = c2 * 97 + b[i][j] - 'a' + 1;
            w = c1 * pwpwpw[j+1] * 97 + c2;
            auto it = mp.find(w);
            if (it == mp.find_end()) mp[w] = cnt;
            else cnt = it->se;
        }
        mp[w]++;
    }
    rep(_, 1, m) {
        string u, v;
        cin >> u >> v;
        int len = u.size();
        rep(i, 0, len-1) {
            hsh__1[i+1] = hsh__1[i] * 97 + u[i] - 'a' + 1;
            hsh__2[i+1] = hsh__2[i] * 97 + v[i] - 'a' + 1;
        }
        int l = 1, r = len;
        while (u[l-1] == v[l-1]) l++;
        while (u[r-1] == v[r-1]) r--;
        int cnt = 0;
        rep(i, 1, l) {
            int L = i-1, R = len;
            while (L < R) {
                int mid = (L+R+1) >> 1;
                ull w = getw(i, mid);
                if (mid < i || mp.find(w) != mp.find_end()) {
                    L = mid;
                } else {
                    R = mid-1;
                }
            }
            if (L < r) continue;
            cnt += mp[getw(i, L)];
            if (i != r) cnt -= mp[getw(i, r-1)];
        }
        cout << cnt << endl;
    }
}