#include <iostream>
#include <string>
using namespace std;

string s[1005][2], t[1005][2];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i][0] >> s[i][1];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> t[i][0] >> t[i][1];
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (t[i][0].size() < s[j][0].size()) continue;
            for (int k = 0; k <= t[i][0].size() - s[j][0].size(); k++)
            {
                string temp = t[i][0];
                bool flag = 0;
                for (int x = k; x < k + s[j][0].size(); x++)
                {
                    if (temp[x] != s[j][0][x - k])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                {
                    for (int x = k; x < k + s[j][0].size(); x++)
                    {
                        temp[x] = s[j][1][x - k];
                    }
                }
                if (temp == t[i][1]) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
