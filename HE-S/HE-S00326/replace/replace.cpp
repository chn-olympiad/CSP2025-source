#include<bits/stdc++.h>

using namespace std;

// #define int long long

const int N = 2e5 + 100;


using ull = __uint64_t;
constexpr ull p = 1331;
int n, q;
string s[N][2];
ull hs[N][2];
int len[N];
vector<int> hsl[200];
unordered_map<ull, unordered_map<ull, int> > mp;

ull th1[5000000 + 100];
ull th2[5000000 + 100];
ull pp[5000000 + 100];

inline ull shs1(int l, int r) {
    if(l > r) return 0;
    return th1[r] - (l - 1 < 0 ? 0ull : th1[l - 1]) * pp[r - l + 1];
}
inline ull shs2(int l, int r) {
    if(l > r) return 0;
    return th2[r] - (l - 1 < 0 ? 0ull : th2[l - 1]) * pp[r - l + 1];
}   
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i][0] >> s[i][1];
        len[i] = s[i][0].size();
        mx = max(mx, len[i]);
        hsl[s[i][0][0]].push_back(len[i]);
        for(char t : s[i][0]) 
            hs[i][0] = hs[i][0] * p + t;
        for(char t : s[i][1]) 
            hs[i][1] = hs[i][1] * p + t;
        mp[hs[i][0]][hs[i][1]] ++;
    }
    for(int i = 1; i <= 190; i ++) {
        if(hsl[i].empty()) continue;
        sort(hsl[i].begin(), hsl[i].end());
        hsl[i].erase(unique(hsl[i].begin(), hsl[i].end()), hsl[i].end());
    }
    pp[0] = 1;
    for(int i = 1; i <= mx; i ++) {
        pp[i] = pp[i - 1] * p;
    }
    for(int i = 1; i <= q; i ++) {
        int ans = 0;
        string t1, t2;
        cin >> t1 >> t2;
        int ll = t1.size();
        for(int i = 0; i < ll; i ++) {
            th1[i] = t1[i] + th1[i - 1] * p;
            th2[i] = t2[i] + th2[i - 1] * p;
        }
        int ml = 0, mr = 0;
        for(ml = 0; ml < ll; ml ++) 
            if(t1[ml] != t2[ml]) {
                ml --;
                break;
            }
        for(mr = ll - 1; mr >= 0; mr --) 
            if(t1[mr] != t2[mr]) {
                mr ++;
                break;
            }
        for(int i = 0; i <= ml + 1; i ++) {
            if(hsl[t1[i]].empty()) continue;

            int now = lower_bound(hsl[t1[i]].begin(), hsl[t1[i]].end(), mr - i) - hsl[t1[i]].begin();

            for(int j = now, L; j < hsl[t1[i]].size(); j ++) {
                L = hsl[t1[i]][j];
                if(i + L < mr) continue;
                if(i + L - 1 >= ll) break;
                ull t1 = shs1(i, i + L - 1);
                ull t2 = shs2(i, i + L - 1);
                if(mp.count(t1)) {
                    if(mp[t1].count(t2)) {
                        ans += mp[t1][t2];
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}