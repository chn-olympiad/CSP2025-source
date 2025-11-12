#include <bits/stdc++.h>

using namespace std;
bool cmp(char c, char d)
{
    return c > d;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s, s1 = "";
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9') s1 += s[i];
    }
    sort(s1.begin(), s1.end(), cmp);
    cout << s1 << endl;
    return 0;
}
