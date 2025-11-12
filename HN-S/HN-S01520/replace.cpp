#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, q;
string s1[N], s2[N], t1, t2;
map<string, set<string>> mp;

void solve(){
    cin >> t1 >> t2;
    int m = t1.size();
    ll ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = i; j < m; j++){
            ///cout << i << ' ' << j << ' ' << t1.substr(0, i) << ' ' << t2.substr(0, i) << ' ';
            if(t1.substr(0, i) == t2.substr(0, i) && (j == m - 1 || t1.substr(j + 1) == t2.substr(j + 1))){
                ans += mp[t1.substr(i, j - i + 1)].count(t2.substr(i, j - i + 1));
            }
            ///cout << ans << '\n';
        }
    }
    cout << ans << '\n';
}

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> s1[i] >> s2[i];
        mp[s1[i]].insert(s2[i]);
    }
    while(q--){
        solve();
    }
    return 0;
}
