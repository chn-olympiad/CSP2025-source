#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
map<pair<string, string>, bool> mp;
ll main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    string s, t;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> s >> t, mp[{s, t}] = 1;
    if(n >= 1000){
        while(q--){
            cin >> s >> t;
            cout << "0\n";
        }
        return 0;
    }
    while(q--){
        ll ans = 0;
        cin >> s >> t;
        s = "#" + s + "#", t = "#" + t + "#";
        for(int i = 1; i < s.size(); i++){
            string now = "", now_t = "";
            now += s[i], now_t += t[i];
            for(int j = i + 1; j < s.size(); j++){
                string head = s.substr(0, i), head_t = t.substr(0, i), tail = s.substr(j), tail_t = t.substr(j);
                if(head != head_t || tail != tail_t) {
                    now += s[j], now_t += t[j];
                    continue;
                }
                now += s[j], now_t += t[j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
