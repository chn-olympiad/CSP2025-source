#include<bits/stdc++.h>
using namespace std;
ci maxn = 2e5 + 5;
int n, q;
string s[maxn];
map<string, string> M;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        string x, y;
        cin >> x >> y;
        s[i] = x;
        M[x] = y;
    }
    for(int o = 1; o <= q; o++){
        int ans = 0;
        string tar, now;
        cin >> now >> tar;
        for(int l = 0; l < now.size(); l++){
            for(int len = 1; l + len - 1 < now.size(); r++){
                for(int i = 1; i <= n; i++)
                if(now.substr(l, len) == s[i])
                    if(now.substr(0, l - 0 + 1) + M[s[i]] + now.substr(l + len, now.size() - l + len - 1) == tar) ans++;
            }
        }
    cout << ans << '\n';
    }
}
