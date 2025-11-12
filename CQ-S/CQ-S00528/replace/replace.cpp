#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

ll n, q;
vector<pair<string, string>> s;
vector<vector<int>> border[2];
vector<int> tb[2];
string t1, t2;
void kmp(string &s, vector<int> &border)
{
    border.resize(s.size() + 1);
    for (int i = 1, p = 0; i < s.size(); i++)
    {
        while (p && s[p] != s[i])
            p = border[p - 1];
        if (s[p] == s[i])
            p++;
        border[i] = p;
    }
}

bool cmp(string &s, int L, int R, string &a)
{
    for (int i = L; i <= R; i++)
        if (s[i] != a[i - L])
            return false;
    return true;
}

pair<int, int> code(string &s)
{
    ll v = s.find_first_of('b');
    return pair<int, int>{v, s.size() - v - 1};
}
void work2()
{
    vector<pair<int, int>> S[2];
    S[0].resize(n + 1), S[1].resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        S[0][i] = code(s[i].first);
        S[1][i] = code(s[i].second);
    }
    for (int i = 1; i <= q; i++)
    {
        pair<int, int> d1, d2;
        ll ans = 0;
        cin >> t1 >> t2;
        d1 = code(t1), d2 = code(t2);
        for (int j = 1; j <= n; j++)
        {
            if (S[0][j].second > d1.second || S[0][j].first > d1.first || S[1][j].second > d2.second || S[1][j].first > d2.first)
                continue;
            int bg = d1.first - S[0][j].first;
            if (bg + S[1][j].first == d2.first)
                ans++;
        }
        cout << ans << endl;
    }
}

ll l1;
bool flag = 1;
void ck(string &s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] != 'a' && s[i] != 'b')
            flag = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin >> n >> q;
    s.resize(n + 1), border[0].resize(n + 1), border[1].resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> t1 >> t2;
        s[i].first = t1, s[i].second = t2;
        kmp(t1, border[0][i]), kmp(t2, border[1][i]);
        l1 += t1.size();
        ck(t1), ck(t2);
    }
    if (flag && (l1 >= 5e3 || n >= 1e4 || q >= 1e4))
    {
        work2();
        return 0;
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> t1 >> t2;
        ll L = 0, R = t1.size() - 1, ans = 0;
        while (L < t1.size() && t1[L] == t2[L])
            L++;
        while (R >= 0 && t1[R] == t2[R])
            R--;
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0, p = 0; k < t1.size(); k++)
            {
                while (p && t1[k] != s[j].first[p])
                    p = border[0][j][p - 1];
                if (t1[k] == s[j].first[p])
                    p++;
                if (p == s[j].first.size())
                {
                    int a = k - s[j].first.size() + 1, b = k;
                    if (a <= L && R <= b && cmp(t2, a, b, s[j].second))
                    {
                        ans++;
                    }
                    p = border[0][j][p - 1];
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}