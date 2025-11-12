#include <bits/stdc++.h>
using namespace std;
struct node{
    int l, r;
    string s1, s2;
};
map<string, vector<node> > m;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
    string s1, s2;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> s1 >> s2;
        int l = 0, r = s1.size();
        while (l < r && s1[l] == s2[l]) l++;
        while (r >= 0 && s1[r] == s2[r]) r--;
        string ns;
        for (int i = l; i <= r; i++) ns += s1[i];
        m[ns].push_back(node{l, r, s1, s2});
    }
    for (int i = 1; i <= q; i++){
        cin >> s1 >> s2;
        if (s1.size() != s2.size()){
            cout << 0 << '\n';
            continue;
        }
        int l = 0, r = s1.size();
        while (l < r && s1[l] == s2[l]) l++;
        while (r >= 0 && s1[r] == s2[r]) r--;
        string ns;
        for (int i = l; i <= r; i++) ns += s1[i];
        if (!m.count(ns)){
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 0; i < m[ns].size(); i++){
            int nl = m[ns][i].l;
            bool f = 1;
            for (int j = 0; j < m[ns][i].s1.size(); j++){
                if (s1[j+l-nl] != m[ns][i].s1[j] || s2[j+l-nl] != m[ns][i].s2[j]){
                    f = 0;
                    break;
                }
            }
            if (f) ans++;
        }
        cout << ans << endl;
    }
	return 0;
}
