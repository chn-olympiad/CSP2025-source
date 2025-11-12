# include <bits/stdc++.h>
using namespace std;
int n, q;
string sf[200100], sc[200100];
string tmpf, tmps;
string a, b;
map<pair<string, string>, int> vis;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
    {
        cin >> sf[i] >> sc[i];
        tmpf = ""; tmps = "";
        for (int j = 0; j < sf[i].size(); j ++)
        {
            if (sf[i][j] != sc[i][j])
            {
                tmpf += sf[i][j];
                tmps += sc[i][j];
            }
        }
        vis[make_pair(tmpf, tmps)]++;
        sf[i] = tmpf;
        sc[i] = tmps;
        //cout << tmpf << " " << tmps << endl;

    }
    for (int i = 1; i <= q; i ++)
    {
        cin >> a >> b;
        tmpf = ""; tmps = "";
        for (int j = 0; j < a.size(); j ++)
        {
            if (a[j] != b[j])
            {
                tmpf += a[j];
                tmps += b[j];
            }
        }

        cout << vis[make_pair(tmpf, tmps)] << endl;
    }
    return 0;
}
