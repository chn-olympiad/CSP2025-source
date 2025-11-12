#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
map<pair<string, string>, int> m;
int n, q;
pair<string, string> find_change(string s1, string s2)
{
    int cur;
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] != s2[i])
        {
            cur = i;
            int len = (int)s1.size() - i;
            for(int j = (int)s1.size() - 1; j >= i; j--)
            {
                if(s1[j] != s2[j])
                    break;
                else
                    len--;
            }
            return make_pair( s1.substr(cur, len), s2.substr(cur, len) );
        }
    }
}
signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if(s1 == s2)    continue;
        m[find_change(s1, s2)]++;
        //cout << find_change(s1, s2).first << " " << find_change(s1, s2).second <<endl;
    }
    while(q--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if(s1.size() != s2.size())
        {
            cout << 0 <<endl;
            continue;
        }
        cout << m[find_change(s1, s2)] <<endl;
    }
    return 0;
}
