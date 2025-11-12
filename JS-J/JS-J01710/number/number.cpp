#include <bits/stdc++.h>
using namespace std;

string s;
int res[10000000];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int cnt = 0;
    string ans = "";
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if ('0' <= s[i]  && s[i] <= '9')
        {
            res[cnt] = s[i] - '0';
            cnt++;
        }
    }
    sort(res, res + cnt + 1, cmp);
    for (int i = 0; i < cnt; i++)
    {
        ans += to_string(res[i]);
    }
    cout << ans << endl;
    return 0;
}
