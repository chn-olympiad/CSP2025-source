#include <bits/stdc++.h>
using namespace std;
int n, q, ans = 0;
int w1, wn;
struct node
{
    string s1, s2;
}a[200005];
bool check(int l, string sa, string o, string r, int w2)
{
    string t = o;
    if (w1 < w2) return 0;
    int be = w1 - w2;
    for (int i = be; i < be + a[l].s1.size(); i++)
    {
        if (a[l].s1[i - be] != t[i]) return 0;
        t[i] = a[l].s2[i - be];
    }
    if (t == r) return 1;
    else return 0;
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i].s1 >> a[i].s2;
    while (q--)
    {
        ans = 0;
        string x, y;
        cin >> x >> y;
        string temp = "";
        bool flag = 0;
        for (int i = 0; i < x.size(); i++)
        {
            if (flag == 1 && x[i] != y[i]) temp += x[i];
            else if (x[i] != y[i]) temp += x[i], flag = 1, w1 = i;
            else if (flag == 1 && x[i] == y[i])
            {
                wn = i;
                break;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < a[i].s1.size(); j++)
            {
                string cnt = "";
                for (int k = j; k < j + temp.size(); k++) cnt += a[i].s1[k];
                if (cnt == temp && check(i, temp, x, y, j)) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
