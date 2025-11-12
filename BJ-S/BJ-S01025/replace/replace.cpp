#include <bits/stdc++.h>
using namespace std;
int n, q, cnt, len, l, r, a, b;
string s1, s2, z1, z2, suba, subb;
map <string, string> m;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1 >> s2;
        m[s1] = s2;
    }
    while (q--)
    {
        cnt = 0;
        cin >> z1 >> z2;
        len = z1.size();
        for (int i = 0; i < len; i++)
            if (z1[i] != z2[i])
            {
                l = i;
                break;
            }
        for (int i = len-1; i >= 0; i--)
            if (z1[i] != z2[i])
            {
                r = i;
                break;
            }
        a = l, b = len-r-1;
        for (int i = 0; i <= a; i++)
        {
            suba = "", subb = "";
            for (int k = i; k < r; k++)
                suba += z1[k], subb += z2[k];
            for (int j = b; j >= 0; j--)
            {
                suba += z1[len-j-1], subb += z2[len-j-1];
                if (m.find(suba) != m.end() && m[suba] == subb)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}