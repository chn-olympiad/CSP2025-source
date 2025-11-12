#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, q;
string s1[N], s2[N];
string t1, t2;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i ++ )
       cin >> s1[i] >> s2[i];

    while (q -- )
    {
        cin >> t1 >> t2;
        int res = 0;
        for (int i = 1; i <= n; i ++ )
        {
            for (int j = 0; j < t1.size(); j ++ )
            {
                if (t1[j] == s1[i][0])
                    if (s1[i] == t1.substr(j, s1[i].size()))
                        if (t1.substr(0, j) == t2.substr(0, j) && s2[i] == t2.substr(j, s2[i].size()) && t1.substr(j + s1[i].size()) == t2.substr(j + s1[i].size()))
                        {
                            res ++ ;
                            break;
                        }
            }
        }

        printf("%d\n", res);
    }

    return 0;
}
