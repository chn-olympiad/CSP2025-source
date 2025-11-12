#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 13337, MOD = 1e9 + 7;
const int NR = 1e5, MR = 5e6;
int n, q;
struct node
{
    int s1, s2, dig;
}s[NR + 7];
int pre1[MR + 7], pre2[MR + 7];
int mul[MR + 7];

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    mul[0] = 1;
    for(int i = 1; i <= MR; i++)
        mul[i] = (mul[i - 1] * M) % MOD;
    cin >> n >> q;
    string sk;
    getline(cin, sk);
    for(int i = 1; i <= n; i++)
    {
        getline(cin, sk);
        for(int j = 0; j < (sk.length() - 1) / 2; j++)
            s[i].s1 = (s[i].s1 * M + (sk[j] - 'a')) % MOD;
        for(int j = (sk.length() + 1) / 2; j < sk.length(); j++)
            s[i].s2 = (s[i].s2 * M + (sk[j] - 'a')) % MOD;
        s[i].dig = (sk.length() - 1) / 2;
    }
    string tk;
    for(int i = 1; i <= q; i++)
    {
        int t1 = 0, t2 = 0;
        getline(cin, tk);
        int ans = 0, len = (tk.length() - 1) / 2;
        for(int j = 0; j < (tk.length() - 1) / 2; j++)
        {
            t1 = (t1 * M + (tk[j] - 'a')) % MOD;
            pre1[j + 1] = t1;
        }
        for(int j = (tk.length() + 1) / 2; j < tk.length(); j++)
        {
            t2 = (t2 * M + (tk[j] - 'a')) % MOD;
            pre2[j - (tk.length() + 1) / 2 + 1] = t2;
        }
        for(int j = 1; j <= n; j++)
            for(int k = s[j].dig; k <= len; k++)
            {
                if(((pre1[k] - pre1[k - s[j].dig] * mul[s[j].dig])% MOD + MOD) % MOD != s[j].s1) continue;
                if((((t1 - s[j].s1 * mul[len - k]) % MOD + MOD) % MOD + s[j].s2 * mul[len - k]) % MOD == t2) ans++;
            }
        cout << ans << endl;
    }
    return 0;
}
