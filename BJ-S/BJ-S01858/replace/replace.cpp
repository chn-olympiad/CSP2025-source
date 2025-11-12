#include <bits/stdc++.h>
using namespace std;

const int NR = 5e6 + 10;
struct Spr
{
    string a, b;
    int len;
};
Spr a[NR];
int n, Q;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].b;
        a[i].len = a[i].a.length();
    }
    for(int tms = 1; tms <= Q; tms++)
    {
        string s, t;
        cin >> s >> t;
        int m = s.length();
        int finans = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                //cout << "d " << a[j].len << "\n";
                if(a[j].len + i - 1 > m) continue;
                if(s.substr(i - 1, a[j].len) != a[j].a) continue;
                //cout << "asdfgd " << i << " " << j << " " << s.substr(0, i - 1) + a[j].b + s.substr(i + a[j].len - 1) << " " << t << "\n";
                string tt = s.substr(0, i - 1) + a[j].b + s.substr(i + a[j].len - 1);
                if(tt == t) finans++;
            }
        }
        cout << finans << "\n";
    }
    return 0;
}