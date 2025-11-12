#include <bits/stdc++.h>
using namespace std;

int n, Q;
map<string, vector<string>> mp;

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> Q;
    for (int i = 1; i <= n; i++){
        string x, y; cin >> x >> y;
        mp[x].push_back(y);
    }
    while (Q--){
        string x, y; cin >> x >> y;
        int ret = 0;
        for (pair<string, vector<string>> t : mp){
            for (int i = x.find(t.first); i != EOF; i = x.find(t.first, i + 1)){
                for (string v : t.second){
                    string p = x.substr(0, i);
                    string q = x.substr(i + t.first.size());
                    if (p + v + q == y) ret++;
                }
            }
        }
        cout << ret << endl;
    }
    return 0;
}