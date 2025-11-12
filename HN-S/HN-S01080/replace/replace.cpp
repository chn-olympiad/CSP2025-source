#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 5e6 + 5;
int n, Q;
string t[2], s[N][2];

namespace Hash {
    const int base = 13131;
    const int mod = 202510271633773;
    int H[N], pw[N];
    vector<int> h[N][2];
    
    inline void init_hash() {
        pw[0] = 1;

        for(int i = 1 ; i < N ; ++ i)
            pw[i] = pw[i - 1] * base % mod;

        return ;
    }

    inline void init_string(string s, int x, int y) {
        int l = s.size() - 1;

        h[x][y].pb(0ll);

        for(int i = 1 ; i <= l ; ++ i)
            h[x][y].pb((h[x][y][i - 1] * base % mod + s[i]) % mod);

        return ;
    }

    inline void init_String(string s) {
        int l = s.size() - 1;

        for(int i = 1 ; i <= l ; ++ i)
            H[i] = (H[i - 1] * base % mod + s[i]) % mod;

        return ;
    }

    inline int query(int l, int r, int x, int y) {
        return (h[x][y][r] - h[x][y][l - 1] * pw[r - l + 1] % mod + mod) % mod;
    }

    inline int Query(int l, int r) {
        return (H[r] - H[l - 1] * pw[r - l + 1] % mod + mod) % mod;
    }
}

using namespace Hash;

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios_base :: sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init_hash();

    cin >> n >> Q;
    for(int i = 1 ; i <= n ; ++ i) {
        cin >> s[i][0] >> s[i][1];

        s[i][0] = " " + s[i][0], s[i][1] = " " + s[i][1];
        init_string(s[i][0], i, 0), init_string(s[i][1], i, 1);
    }

    while(Q --) {
        cin >> t[0] >> t[1];

        t[0] = " " + t[0], t[1] = " " + t[1];
        init_String(t[0]);

        int l1 = t[0].size() - 1, l2 = t[1].size() - 1, ans = 0;

        for(int i = 1 ; i <= n ; ++ i)
            for(int j = 1 ; j + s[i][0].size() - 2 <= l1 ; ++ j) {
                if(query(1, s[i][0].size() - 1, i, 0) == Query(j, j + s[i][0].size() - 2)) {
                    for(int k = 1 ; k <= l1 ; ++ k) {
                        if(j <= k && k <= j + s[i][0].size() - 2) {
                            if(s[i][1][k - j + 1] != t[1][k]) goto place;
                        }
                        else {
                            if(t[0][k] != t[1][k]) goto place;
                        }
                    }

                    ++ ans;

                    place:;
                }
            }

        cout << ans << '\n';
    }

    return 0;
}