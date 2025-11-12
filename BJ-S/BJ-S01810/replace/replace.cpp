#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int n, q;
string t1, t2;
string s1[N], s2[N];

signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> s1[i] >> s2[i];
    cin >> t1 >> t2;
    int ans = 0;
    for(int i = 0; i < n; i++){
        string t3 = "", t4 = "";
        t3 += t1.substr((t1.size() - s1[i].size()) / 2, (t1.size() - s1[i].size()) / 2);
        t3 += s2[i];
        t3 += t1.substr((t1.size() - s1[i].size()) / 2 + s1[i].size(), (t1.size() - s1[i].size()) / 2 + s1[i].size());
        if(t3 == t2)
            ans++;
    }
    cout << ans;
    return 0;
}
