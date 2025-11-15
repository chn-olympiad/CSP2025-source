#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<string> s(n), e(n);
    for(int i = 0; i < n; i++) cin >> s[i] >> e[i];
    while(q--){
        string x, y;
        cin >> x >> y;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i].size() != e[i].size()) continue;
            int p = x.find(s[i]);
            if(p == x.npos) continue;
            string nx = x.substr(0, p) + e[i] + x.substr(p + s[i].size());
            cnt += nx == y;
        }
        cout << cnt << endl;
    }
    return 0;
}
