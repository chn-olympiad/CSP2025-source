

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = s; i <= t; i++)
#define per(i, s, t) for(int i = t; i >= s; i--)

const ll h1 = 331;
const ll h2 = 3331;
const ll mod = 998244353;

const ll MAXM = 5e6 + 9;

int n, q;
ll h[MAXM];
ll pw[MAXM];
ll hash1[MAXM], hash2[MAXM];
map<ll, pair<ll, int> > mp;

ll GetHash (string s) {

    rep (i, 1, s.length()) {
        h[i] = (h[i - 1] * h1 % mod + (int) s[i - 1]) % mod;
    }

    return h[s.length()];

}

void GetHash1 (string s) {

    rep (i, 1, s.length()) {
        hash1[i] = (hash1[i - 1] * h1 % mod + (int) s[i - 1]) % mod;
    }

}

void GetHash2 (string s) {

    rep (i, 1, s.length()) {
        hash2[i] = (hash2[i - 1] * h1 % mod + (int) s[i - 1]) % mod;
    }

}

ll Hash1 (int l, int r) {

    return (hash1[r] - hash1[l - 1] * pw[r - l + 1] % mod + mod) % mod;

}

ll Hash2 (int l, int r) {

    return (hash2[r] - hash2[l - 1] * pw[r - l + 1] % mod + mod) % mod;

}

string s1, s2;

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ifstream cin("replace.in");
    ofstream cout("replace.out");

    cin >> n >> q;

    pw[0] = 1;

    rep (i, 1, 6e5) {
        pw[i] = pw[i - 1] * h1 % mod;
    }

    rep (i, 1, n) {
        cin >> s1 >> s2;

        mp[GetHash(s1)] = {GetHash(s2), s2.length()};
    }

    rep (i, 1, q) {
        int res = 0;

        cin >> s1 >> s2;

        GetHash1(s1);
        GetHash2(s2);

        rep (i, 1, s1.length()) {
            rep (j, i, s1.length()) {
                pair<ll, int> cur = mp[Hash1(i, j)];

                if (cur.first && cur.first == Hash2(i, i + cur.second - 1) && Hash1(1, i - 1) == Hash2(1, i - 1) && Hash1(j + 1, s1.length()) == Hash2(i + cur.second, s2.length())) {
                    res++;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;

}