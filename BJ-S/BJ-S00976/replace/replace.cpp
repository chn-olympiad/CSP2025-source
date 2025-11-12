#include <bits/stdc++.h>
using namespace std;
int mp[5];
int dp[5000005];
int change(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'b')
        {
            if (i >= 2) return 3;
            if (i == 1) return 2;
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string s, s1;
        cin >> s >> s1;
        mp[change(s1)]++;
    }
    while (q--)
    {
        string s, s1;
        cin >> s >> s1;
        int len = s.size();
        s = " " + s;
        s1 = " " + s1;
        bool f = true;
        string t = "";
        long long cnt = 0;
        for (int i = 1; i <= len; i++)
        {
            dp[i] = dp[i - 1];
            if (s1[i] == 'b')
            {
                if (i >= 3)
                {
                    cnt += mp[i];
                }
                else if (i == 2)
                {
                    cnt += mp[2];
                }
                else cnt += mp[1];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
