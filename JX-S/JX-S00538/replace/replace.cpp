#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define xx first
#define yy second
const int N = 2e5 + 10, M = 5e6 + 10, base = 13331, mod1 = 998244353, mod2 = 1e9 + 7;
int n, q;
ll h1[M], h2[M], p1[M], p2[M];
unordered_map<ll, int> vis;
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    p1[0] = p2[0] = 1;
    for(int i = 1; i < M; i ++){
        p1[i] = p1[i - 1] * base % mod1;
        p2[i] = p2[i - 1] * base % mod2;
    }
    for(int i = 1; i <= n; i ++){
        string s1, s2;
        cin >> s1 >> s2;
        if(s1 == s2)continue;
        int m = s1.size();
        s1 = ' ' + s1, s2 = ' ' + s2;
        ll res1 = 0, res2 = 0;
        for(int i = 1; i <= m; i ++){
            res1 = (res1 * base % mod1 + (s1[i] - 'a' + 1) * 27 + (s2[i] - 'a' + 1)) % mod1;
            res2 = (res2 * base % mod2 + (s1[i] - 'a' + 1) * 27 + (s2[i] - 'a' + 1)) % mod2;
        }
        vis[res1 * res2] ++;
    }
    while(q --){
        string s1, s2;
        cin >> s1 >> s2;
        if(s1.size() != s2.size()){
            cout << "0\n";
            continue;
        }
        int res = 0;
        int m = s1.size();
        s1 = ' ' + s1, s2 = ' ' + s2;
        int l = 0, r = m + 1;
        for(int i = 1; i <= m; i ++){
            if(s1[i] == s2[i])l = i;
            else break;
        }
        for(int i = m; i >= 1; i --){
            if(s1[i] == s2[i])r = i;
            else break;
        }
        for(int i = 1; i <= m; i ++){
            h1[i] = (h1[i - 1] * base % mod1 + (s1[i] - 'a' + 1) * 27 + (s2[i] - 'a' + 1)) % mod1;
            h2[i] = (h2[i - 1] * base % mod2 + (s1[i] - 'a' + 1) * 27 + (s2[i] - 'a' + 1)) % mod2;
        }
        for(int i = r - 1; i <= m; i ++){
            for(int j = l + 1; j >= 1; j --){
                ll hh1 = (h1[i] - h1[j - 1] * p1[i - j + 1] % mod1 + mod1) % mod1;
                ll hh2 = (h2[i] - h2[j - 1] * p2[i - j + 1] % mod2 + mod2) % mod2;
                if(vis.count(hh1 * hh2))res += vis[hh1 * hh2];
            }
        }
        cout << res << '\n';
    }
    return 0;
}