#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int base = 127, mod = 1145141;
const int MAXN = 5e6 + 100;

ll qpow(int a, int b) {
    ll res = 0;
    while(b) {
        if(b & 1) res *= a; b >>= 1;
        a *= a;
        res %= base, a %= base;
    }
    return res;
}

int gethash(string s) {
    ll res = 0;
    for(int i = 0; i < s.size(); i ++) {
        res = (res * base + s[i] - 'a') % mod;
    }
    return res;
}

int hash1[MAXN], hash2[MAXN];

signed main(){
	ios::sync_with_stdio(false), cin.tie(0);
	 freopen("replace.in", "r", stdin);
	 freopen("replace.out", "w", stdout);
    int n, q;cin >> n >> q;
    string s1, s2;
    vector<pair<string, string> > vec (0);
    for(int i = 1; i <= n; i ++) {
        cin >> s1 >> s2;
        vec.push_back({s1, s2});
    }
    string str1, str2;
    while(q --) {
        cin >> str1 >> str2;str1 = ' ' + str1, str2 = ' ' + str2;
        if(str1.size() != str2.size()) {
            cout << "0\n";
            continue ;
        }
        for(int i = 1; i < str1.size(); i ++) {
            hash1[i] = (hash1[i - 1] * base + str1[i] - 'a') % mod;
            hash2[i] = (hash2[i - 1] * base + str2[i] - 'a') % mod;
        }
        int ans = 0;
        for(int k = 0; k < n; k ++) {
            for(int i = 1; i < str1.size(); i ++) {
                int j = i + vec[k].first.size() - 1;
                if(j >= str1.size()) break;
                if(qpow(base, i - 1) * gethash(vec[k].first) == (hash1[j] - hash1[i - 1] * qpow(base, j - 1)) && qpow(base, i - 1) * gethash(vec[k].second) == (hash2[j] - hash2[i - 1] * qpow(base, j - 1))) {
                    ans ++;
                }
            }    
        }
        cout << ans << '\n';
    }
	return 0;
}
/*
4 2
xabcx
xadex
ab cd
bc de
aa bb
xabcx
xadex
aaaa bbbb
0
0
*/

