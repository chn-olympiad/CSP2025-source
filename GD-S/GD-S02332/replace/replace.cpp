#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, q;
string s1[MAXN], s2[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> s1[i] >> s2[i];
    string t1, t2;
    while (q--)
    {
        cin >> t1 >> t2;
        if(t1.size()!=t2.size()){
            cout<<"0\n";
            continue;
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            int len = s1[i].size();
            for (int j = 0; j + len - 1 < (int)t1.size(); ++j)
                cnt += (t1.substr(j, len) == s1[i] && t1.substr(0, j) + s2[i] + t1.substr(j + len) == t2);
        }
        cout << cnt << '\n';
    }
    return 0;
}