#include <iostream>
using namespace std;

string s[100010], t[100010];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> t[i];
    }
    for (int i = 1; i <= q; i++)
    {
        string a, b;
        int cnt = 0;
        cin >> a >> b;
        for (int j = 1; j <= n; j++)
        {
            if (b.size() - a.size() != t[j].size() - s[j].size())  continue;
            for (int k = 0; k < a.size(); k++)
            {
                bool f = true;
                for (int l = k, c = 0; c < s[j].size(); c++, l++)
                {
                    if (l >= a.size() || a[l] != s[j][c])
                    {
                        f = false;
                        break;
                    }
                }
                if (f)
                {
                    string c = "";
                    for (int l = 0; l < k; l++)  c += a[l];
                    c += t[j];
                    for (int l = k + s[j].size(); l < a.size(); l++)  c += a[l];
                    if (c == b)  cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}