#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, q, ans;
unordered_map<string, string> rep;
signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        string s, t;
        cin >> s >> t;
        rep[s] = t;
    }
    while(q--) {
        ans = 0;
        string s, t;
        cin >> s >> t;
        int sl = s.size(), tl = t.size();
        for(int i = 0; i < sl; i++) {
            string sub;
            for(int j = i; j < sl; j++) {
                sub += s[j];
                if(rep.count(sub)) {
                    if(!t.compare(s.substr(0,i)+rep[sub]+s.substr(j+1,sl-j))) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}