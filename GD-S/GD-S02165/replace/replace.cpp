#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, M = 5e6 + 5, mod = 1e9 + 7, base = 13331;
int n, q, dif[N], st[N], ed[N], slen[N];
string s[N][2], t[N][2];
unordered_map <int, vector <int>> mp;
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
    {    
        cin >> s[i][0] >> s[i][1];
        int len = s[i][0].length(), ldif = -1, flag = -1;
        for (int j = len - 1; j >= 0; j --)
        {
            if (s[i][0][j] != s[i][1][j])
            {
                ldif = j;
                break;
            }
        }
        for (int j = 0; j <= ldif; j ++)
        {
            if (s[i][0][j] != s[i][1][j] && flag == -1)
            {
                flag = j;
            }
            
            if (flag != -1)
            {
                dif[i] = (dif[i] * base + (s[i][0][j] - s[i][1][j]) + mod) % mod;
            }
        }
        mp[dif[i]].push_back(i);
        st[i] = flag;
        ed[i] = ldif;
        slen[i] = len;
        //cout << flag << " " << ldif << endl;
    }
    while (q --)
    {
        string t1, t2;
        cin >> t1 >> t2;
        int flag = -1, len = t1.length(), len2 = t2.length(), ans = 0;
        if (len != len2)
        {
            cout << 0 << endl;
            continue;
        }
        int ldif = -1, dif = 0;
        for (int j = len - 1; j >= 0; j --)
        {
            if (t1[j] != t2[j])
            {
                ldif = j;
                break;
            }
        }
        for (int j = 0; j <= ldif; j ++)
        {
            if (t1[j] != t2[j] && flag == -1)
            {
                flag = j;
            }
            
            if (flag != -1)
            {
                dif = (dif * base + (t1[j] - t2[j]) + mod) % mod;
            }
        }
        //cout << flag << " " << ldif << endl;
        for (auto id : mp[dif])
        {
            
            if (st[id] > flag || slen[id] + flag - st[id] - 1 >= len) 
                continue;
            int fp = flag - st[id];
            int flag = 1;
            for (int i = 0; i < slen[id]; i ++)
            {
                if (t1[i + fp] != s[id][0][i] || t2[i + fp] != s[id][1][i])
                {    
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}