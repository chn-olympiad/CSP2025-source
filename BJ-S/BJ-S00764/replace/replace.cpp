#include <bits/stdc++.h>
using namespace std;

int n, q, ans, minx, maxx;
string s[200005][2], t[2];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i][0] >> s[i][1];
    }
    for(int i = 1; i <= q; i++)
    {
        ans = 0, minx = 99999, maxx = 0;
        cin >> t[0] >> t[1];
        for(int j = 0; j < t[0].length(); j++)
        {
            if(t[0][j] != t[1][j])  maxx = j;
            if(t[0][j] != t[1][j] && minx == 99999)  minx = j;
        }
        for(int j = 0; j <= minx; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                if(s[k][0].length() + j > t[0].length())  continue;
                if(s[k][0].length() + j < maxx)  continue;
                bool flag = true;
                for(int l = 0; l < s[k][0].length(); l++)
                {
                    if(s[k][0][l] != t[0][l + j] || s[k][1][l] != t[1][l + j])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)  ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
