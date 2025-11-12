#include <bits/stdc++.h>
using namespace std;

const int NR = 2e5 + 5;
string s[NR], t[NR];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s[i] >> t[i];

    while (q--)
    {
        int ans = 0;
        string a, b;
        cin >> a >> b;
        int l1 = a.size(), l2 = b.size();
        if (l1 != l2)
        {
            cout << 0 << endl;
            continue;
        }

        int minL = l1 - 1, maxR = 0;
        for (int i = 0; i <= l1 - 1; i++)
            if (a[i] != b[i]) minL = min(minL, i), maxR = max(maxR, i);
        
        for (int len = 1; len <= l1; len++)
            for (int l = 0; l + len - 1 <= l1 - 1; l++)
            {
                int r = l + len - 1;
                if (l <= minL && maxR <= r)
                {
                    for (int i = 1; i <= n; i++)
                    {
                        if (s[i].size() != len) continue;
                        string c = "";
                        for (int j = 0; j <= l1 - 1; j++)
                        {
                            if (j < l || j > r) c += a[j];
                            else
                            {
                                if (a[j] != s[i][j - l]) break;
                                c += t[i][j - l];
                            }
                        }

                        // cout << l + 1 << " -> " << r + 1 << ": " << i << ", " << c.size() << " " << c << " " << b.size() << " " << b << " 1" << endl;

                        if (c.size() != b.size()) continue;
                        bool flag = true;
                        for (int j = 0; j <= c.size() - 1; j++)
                        {
                            if (c[j] != b[j])
                            {
                                flag = false;
                                break;
                            }
                        }
                        ans += flag;
                    }
                }
            }
        cout << ans << endl;
    }
    return 0;
}