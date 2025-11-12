#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, ans;
string s[N][3];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
    while (q--)
    {
        ans = 0;
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < t1.size(); i++)
        {
            for (int j = i; j < t1.size(); j++)
            {
                string tmp = "";
                for (int k = i; k <= j; k++) tmp += t1[k];
                for (int k = 1; k <= n; k++)
                {
                    string t3 = t1;
                    if (tmp == s[k][1])
                    {
                        for (int l = i; l <= j; l++) t3[l] = s[k][2][l - i];
                    }
                    if (t2 == t3) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
