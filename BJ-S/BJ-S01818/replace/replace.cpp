#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <string>
using namespace std;
int n, q, ans;
vector< pair<string, string> > v;
void dfs(string s, string t, vector<bool> vis) {
    if (s == t) {
        ans++;
    }
    for (int i = 1; i < int(vis.size()); i++) {
        if (!vis[i]) {
            int f = s.find(v[i].first);
            if (f != -1) {
                vis[i] = true;
                string ns = s;
                for (int j = 0; j < int(v[i].first.size()); j++) {
                    ns[f + j] = v[i].second[j];
                }
                dfs(ns, t, vis);
            }
        }
    }
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string k1, k2;
        cin >> k1 >> k2;
        v.push_back({k1, k2});
    }
    for (int i = 1; i <= q; i++) {
        string from, to;
        cin >> from >> to;
        dfs(from, to, vector<bool>(v.size() + 1, false));
        cout << ans << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
