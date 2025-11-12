#include <iostream>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 5;
struct T
{
    string s1, s2;
    bool operator< (const T &a) const
    {
        return s1 < a.s1;
    }
}s[N];
int n, q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> s[i].s1 >> s[i].s2;
    sort(s + 1, s + n + 1);
    string t1, t2;
    while (q--)
    {
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << 0 << endl;
            continue;
        }
        int num = 0, ans = 0;
        for (int i = 0; i < t1.size(); i++)
            if (t1[i] != t2[i])
                num = i;
        for (int i = 0; t1[i - 1] == t2[i - 1]; i++)
        {
            for (int j = 1; j <= n && i + s[j].s1.size() - 1 >= num; j++)
            {
                for (int k = 0, ii = i; k < s[j].s1.size(); ii++, k++)
                    if (t1[ii] != s[j].s1[k] || t2[ii] != s[j].s2[k])
                    {
                        ans--;
                        break;
                    }
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
