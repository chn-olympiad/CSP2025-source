#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
namespace solve15{
    const int N = 2e5 + 10, K1 = 131, K2 = 13331, m1 = 8e8 - 1, m2 = 1e9 + 114514;
    ll h11[N], h21[N], h12[N], h22[N], mul1[N], mul2[N];
    map<int,map<pair<pair<ll,ll>,pair<ll,ll>>,int>>mp;
    ll hashh(string s, int k, int m){
        ll ans = 0;
        for (char c : s)
            ans = (ans * k % m + c) % m;
        return ans;
    }
    ll subhash(int l, int r, ll h[], ll mul[], ll m){
        return (h[r] - h[l-1] * mul[r - l + 1] % m + m) % m;
    }
    void run(){
        for (int i = 1; i <= n; i++){
            string s1, t1;
            cin >> s1 >> t1;
            mp[s1.size()][{{hashh(s1, K1, m1), hashh(t1, K1, m1)},{hashh(s1, K2, m2), hashh(t1, K2, m2)}}]++;
        }
        mul1[0] = mul2[0] = 1;
        for (int i = 1; i < N; i++)
            mul1[i] = mul1[i-1] * K1 % m1, mul2[i] = mul2[i-1] * K2 % m2;
        while (q--){
            string s1, s2;
            cin >> s1 >> s2;
            if (s1.size() != s2.size()){
                cout << 0 << endl;
                continue;
            }
            int len = s1.size();
            s1 = ' ' + s1, s2 = ' ' + s2;
            for (int i = 1; i <= len; i++){
                h11[i] = (h11[i-1] * K1 % m1 + s1[i]) % m1;
                h21[i] = (h21[i-1] * K2 % m2 + s1[i]) % m2;
                h12[i] = (h12[i-1] * K1 % m1 + s2[i]) % m1;
                h22[i] = (h22[i-1] * K2 % m2 + s2[i]) % m2;
            }
            int mn = len, mx = 1;
            for (int i = 1; i <= len; i++)
                if (s1[i] != s2[i])
                    mn = min(mn, i), mx = max(mx, i);
            int ans = 0;
            for (int l = 1; l <= mn; l++)
                for (int r = mx; r <= len; r++)
                    if (l <= r)
                        ans += mp[r - l + 1][{{subhash(l, r, h11, mul1, m1), subhash(l, r, h12, mul1, m1)}, {subhash(l, r, h21, mul2, m2), subhash(l, r, h22, mul2, m2)}}];
            cout << ans << endl;
        }
    }
};
namespace solveA{
    // const int L = 5e6 + 10;
    map<int,vector<int>>mp;
    void run(){
        while (n--){
            string s, t;
            cin >> s >> t;
            int spos = s.find('b'), tpos = t.find('b');
            mp[tpos-spos].push_back(spos);
        }
        while (q--){
            string s, t;
            cin >> s >> t;
            if (s.size() != t.size()){
                cout << 0 << endl;
                continue;
            }
            int spos = s.find('b'), tpos = t.find('b');
            if (!mp.count(tpos - spos)){
                cout << 0 << endl;
                continue;
            }
            vector<int> v = mp[tpos - spos];
            sort(v.begin(), v.end());
            if (v[0] > spos){
                cout << 0 << endl;
                continue;
            }
            cout << upper_bound(v.begin(), v.end(), spos) - v.begin() << endl;
        }
    }
};
int main(){
    freopen("replace.in", "r", stdin);    
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    // cout << n << ' ' << q << endl;
    if (n <= 1000){
        solve15::run();
        return 0;
    }
    solveA::run();
    return 0;
}