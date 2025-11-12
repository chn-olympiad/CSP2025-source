#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5, M = 5e6 + 5;
const int bas[2] = {233, 301}, mod[2] = {100000007, 998244353};

int n, q;
ll ans;
string s[N], t[N], a, b;

struct HAS{
    vector<int> bd[2], qp[2];
    void init(string s){
        for(int j = 0; j < 2; j++) bd[j].clear(), qp[j].clear();
        for(int i = 0; i < s.size(); i++) for(int j = 0; j < 2; j++) bd[j].push_back(0), qp[j].push_back(1);
        for(int i = 1; i < s.size(); i++) for(int j = 0; j < 2; j++) bd[j][i] = (1ll * bd[j][i - 1] * bas[j] + s[i]) % mod[j];
        for(int i = 1; i < s.size(); i++) for(int j = 0; j < 2; j++) qp[j][i] = 1ll * qp[j][i - 1] * bas[j] % mod[j];
    }
    ll query(int l, int r){
        int res1 = (bd[0][r] - 1ll * bd[0][l - 1] * qp[0][r - l + 1] % mod[0] + mod[0]) % mod[0];
        int res2 = (bd[1][r] - 1ll * bd[1][l - 1] * qp[1][r - l + 1] % mod[1] + mod[1]) % mod[1];
        return 1ll * res1 * mod[1] + res2;
    }
}hs, hs2;

map<pair<ll, ll>, int> mp;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> s[i] >> t[i];
        int len = s[i].size();
        hs.init("!" + s[i]);
        ll sum1 = hs.query(1, len);
        hs.init("!" + t[i]);
        ll sum2 = hs.query(1, len);
        mp[{sum1, sum2}]++;
    }
    for(int i = 1; i <= q; i++){
        cin >> a >> b;
        if(a.size() != b.size()){
            cout << "0\n";
            continue;
        }
        int len = b.size();
        a = "!" + a, b = "!" + b;
        hs.init(a), hs2.init(b);
        ans = 0;
        for(int l = 1; l < b.size(); l++){
            for(int r = l; r < b.size(); r++){
                if((l == 1 || hs.query(1, l - 1) == hs2.query(1, l - 1)) && (r == len || hs.query(r + 1, len) == hs2.query(r + 1, len))){
                    ans += mp[{hs.query(l, r), hs2.query(l, r)}];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
