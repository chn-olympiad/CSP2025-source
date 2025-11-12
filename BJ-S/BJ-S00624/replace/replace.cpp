#include <bits/stdc++.h>
using namespace std;

int n, q;
string p[200005][2];

unordered_set<int> kmp(string a, string b){
    string c = b + "#" + a;
    vector<int> p(c.size());
    for (int i = 1; i < c.size(); i++){
        int j = p[i - 1];
        while (j > 0 && c[i] != c[j])
            j = p[j - 1];
        if (c[i] == c[j])
            p[i] = j + 1;
    }
    unordered_set<int> ans;
    for (int i = b.size(); i < c.size(); i++){
        if (p[i] == b.size())
            ans.insert(i - b.size() * 2);
    }
    return ans;
}

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> p[i][0] >> p[i][1];
    for (int i = 1; i <= q; i++){
        string a, b;
        cin >> a >> b;
        int ans = 0, l = n + 1, r = 0;
        for (int j = 0; j < a.size(); j++)
            if (a[j] != b[j])
                l = min(l, j), r = j;
        for (int j = 1; j <= n; j++){
            unordered_set<int> x = kmp(a, p[j][0]), y = kmp(b, p[j][1]);
            for (int k: x)
                if (y.find(k) != y.end() && k <= l && k + p[j][0].size() - 1 >= r)
                    ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
