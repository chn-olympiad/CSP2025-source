#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int base[2] = {131,13331},mod[3] = {998244353,(int)1e9 + 7};

struct hash_e{
    array<int,2> val = {};
    int len = 0;

    hash_e(){val = {};len = 0;}

    bool operator < (const hash_e &oth) const {
        if (len != oth.len) return len < oth.len;
        return val < oth.val;
    }
};

vector<array<hash_e,2>> c[5000100];

using ary = array<hash_e,2>;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n,q;
    cin >> n >> q;

    for (int i = 1;i <= n;i++){
        string s1,s2;
        cin >> s1 >> s2;

        hash_e h1,h2;

        int len = s1.size();

        for (int j = 0;j < len;j++){
            h1.len++,h2.len++;

            for (int k = 0;k < 2;k++){
                h1.val[k] = (h1.val[k] * 1LL * base[k] + s1[j]) % mod[k];
                h2.val[k] = (h2.val[k] * 1LL * base[k] + s2[j]) % mod[k];
            }
        }

        c[h1.len].push_back({h1,h2});
    }

    vector<int> hv;

    for (int i = 1;i <= 5e6;i++){
        if (c[i].empty()) continue;

        hv.push_back(i);

        sort(c[i].begin(),c[i].end());
    }

    for (;q--;){
        string s,t;
        cin >> s >> t;

        i64 ans = 0;

        int len = s.size();
        int ms = len,ma = -1;

        for (int i = 0;i < len;i++)
            if (s[i] != t[i])
                ms = min(ms,i),ma = max(ma,i);

        if (len <= hv.end() - lower_bound(hv.begin(),hv.end(),len)/*/1/**/){
            for (int k = 0;k <= ms;k++){
                hash_e h1,h2;

                for (int l = k;l < max(ma,k);l++){
                    h1.len++,h2.len++;

                    for (int k = 0;k < 2;k++){
                        h1.val[k] = (h1.val[k] * 1LL * base[k] + s[l]) % mod[k];
                        h2.val[k] = (h2.val[k] * 1LL * base[k] + t[l]) % mod[k];
                    }
                }

                for (int l = max(ma,k);l < len;l++){
                    h1.len++,h2.len++;

                    for (int k = 0;k < 2;k++){
                        h1.val[k] = (h1.val[k] * 1LL * base[k] + s[l]) % mod[k];
                        h2.val[k] = (h2.val[k] * 1LL * base[k] + t[l]) % mod[k];
                    }

                    ans += upper_bound(c[h1.len].begin(),c[h1.len].end(),(ary){h1,h2}) - lower_bound(c[h1.len].begin(),c[h1.len].end(),(ary){h1,h2});
                }
            }
        }else{
            for (auto i:hv){
                if (i < ma - ms) continue;

                int id = max(i - 1,ma);

                int pw[2] = {1,1};

                hash_e h1,h2;

                for (int j = 0;j < i;j++){
                    h1.len++,h2.len++;

                    for (int k = 0;k < 2;k++){
                        h1.val[k] = (h1.val[k] * 1LL * base[k] + s[j]) % mod[k];
                        h2.val[k] = (h2.val[k] * 1LL * base[k] + t[j]) % mod[k];
                        pw[k] = (pw[k] * 1LL * base[k]) % mod[k];
                    }
                }

                if (ma < i)
                    ans += upper_bound(c[i].begin(),c[i].end(),(ary){h1,h2}) - lower_bound(c[h1.len].begin(),c[h1.len].end(),(ary){h1,h2});

                for (int j = i;j < len;j++){
                    for (int k = 0;k < 2;k++){
                        h1.val[k] = (h1.val[k] * 1LL * base[k] + s[j]) % mod[k];
                        h2.val[k] = (h2.val[k] * 1LL * base[k] + t[j]) % mod[k];
                        h1.val[k] = (h1.val[k] - pw[k] * 1LL * s[j - i] % mod[k] + mod[k]) % mod[k];
                        h2.val[k] = (h2.val[k] - pw[k] * 1LL * t[j - i] % mod[k] + mod[k]) % mod[k];
                    }

                    if (ms <=  j - i) break;
                    if (ma <= j)
                        ans += upper_bound(c[i].begin(),c[i].end(),(ary){h1,h2}) - lower_bound(c[h1.len].begin(),c[h1.len].end(),(ary){h1,h2});
                }
            }
        }

        cout << ans << '\n';
    }
}
