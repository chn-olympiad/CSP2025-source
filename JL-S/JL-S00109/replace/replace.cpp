#include <bits/stdc++.h>
using namespace std;
const int oo = 2e5 + 100;
int n, q, a[oo], fp;
pair<string, string> f[oo];
map<pair<string, string>, int> ff;

string read()
{
    char ccc = getchar();
    string aaa = "";
    while (ccc < 'a' && ccc > 'z') ccc = getchar();
    while (ccc >= 'a' && ccc <= 'z')
    {
        aaa += ccc;
        ccc = getchar();
    }
    return aaa;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string x, y, z = "", zz = "";
        x = read(), y = read();
        int b, c, d = x.size();
        f[++fp] = make_pair(x, y);
        for (int j = 0; j < d; j++) if (x[j] != y[j]) {b = j; break;}
        for (int j = d - 1; j >= 0; j--) if (x[j] != y[j]) {c = j; break;}
        for (int j = b; j <= c; j++) z += x[j], zz += y[j];
        ff[make_pair(z, zz)]++;
    }
    while (q--)
    {
        string x, y, z = "", zz = "";
        x = read(), y = read();
        int b, c, d = x.size();
        for (int j = 0; j < d; j++) if (x[j] != y[j]) {b = j; break;}
        for (int j = d - 1; j >= 0; j--) if (x[j] != y[j]) {c = j; break;}
        for (int j = b; j <= c; j++) z += x[j], zz += y[j];
        if (!ff[make_pair(z, zz)]) {cout << "0\n"; continue;}
        int ans = 0, r = c - b + 1;
        for (int i = 1; i <= fp; i++)
        {
            int fs = f[i].first.size();
            if (fs < r) continue;
            int xx = x.find(f[i].first);
            if (xx == (int)string::npos || xx > b || xx + fs - 1 < c) continue;
            bool pp = 0;
            string k = f[i].second;
            for (int j = xx; j <= xx + fs - 1; j++)
            {
                if (y[j] != k[j - xx]) {pp = 1; break;}
            }
            if (!pp) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
