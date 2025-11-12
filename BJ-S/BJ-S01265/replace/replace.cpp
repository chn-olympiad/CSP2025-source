#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q;
pair<string, string> a[N];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        a[i] = make_pair(s1, s2);
    }
    for(int i = 1; i <= q; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int ans = 0;
        for(int l = 0; l < s1.size(); l++)
            for(int j = 1; j <= n; j++)
                if(l + a[j].first.size() - 1 < s1.size())
                    if(s1.substr(0, l) + a[j].second + s1.substr(l + a[j].first.size()) == s2)
                        ans++;
        cout << ans << endl;
    }
    return 0;
}
