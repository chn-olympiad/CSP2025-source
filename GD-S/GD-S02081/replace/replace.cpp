#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<ull, ull>
using namespace std;
const int maxn = 5e6 + 50, base = 131313, N = 5e6 + 50;

int n, q, L1, L2, sd, len[N];
string s[maxn][2], t[maxn][2];
ull h[maxn][2], ht[maxn][2], b[N];
mt19937 rnd(time(0));
map<pii, int> mp;

ull gthash(int l, int r, int id){
    if(l > r) return 0;
    return ht[r][id] - b[r - l + 1] * ht[l - 1][id];
}

void solve1(){
    for(int i = 1; i <= q; i++){
        int siz = (int)t[i][0].size();
        if((int)t[i][1].size() != siz){ cout << "0\n"; continue; }
        t[i][0] = " " + t[i][0], t[i][1] = " " + t[i][1];
        mp.clear();
        for(int j = 1; j <= siz; j++){
            ht[j][0] = ht[j - 1][0] * base + t[i][0][j] + sd;
            ht[j][1] = ht[j - 1][1] * base + t[i][1][j] + sd;
        }
        for(int j = 1; j <= siz; j++){
            if(!len[j]) continue;
            for(int l = 1; l <= siz - j + 1; l++){
                int r = l + j - 1;
                if(gthash(1, l - 1, 0) != gthash(1, l - 1, 1)) continue;
                if(gthash(r + 1, siz, 0) != gthash(r + 1, siz, 1)) continue;
                mp[{gthash(l, r, 0), gthash(l, r, 1)}]++;
            }
        }
        // cerr << endl;
        ll res = 0;
        for(int j = 1; j <= n; j++){
            if((int)s[j][0].size() > siz + 1) continue;
            res += mp[{h[j][0], h[j][1]}];

        }
        cout << res << '\n';
    }
}

int main(){
//	freopen("D:/down/replace/replace3.in", "r", stdin);
     freopen("replace.in", "r", stdin);
     freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q, sd = 0, b[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> s[i][0] >> s[i][1];
        int siz = (int)s[i][0].size();
        L1 += siz * 2, len[siz]++;
        s[i][0] = " " + s[i][0], s[i][1] = " " + s[i][1];
        for(int j = 1; j <= siz; j++){
            h[i][0] = h[i][0] * base + s[i][0][j] + sd;
            h[i][1] = h[i][1] * base + s[i][1][j] + sd;
        }
    }
    for(int i = 1; i <= max(L1, L2); i++) b[i] = b[i - 1] * base;
    for(int i = 1; i <= q; i++){
        cin >> t[i][0] >> t[i][1];
        L2 += (int)t[i][0].size() + (int)t[i][1].size();
    }
    solve1();
    return 0;
}
