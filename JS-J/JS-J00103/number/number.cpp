#include <bits/stdc++.h>
using namespace std;
bool cmp(char l, char r)
{
    return l > r;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s1, s2;
    cin >> s1;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] >= '0' && s1[i] <= '9')
        {
            s2 += s1[i];
        }
    }
    sort(s2.begin(), s2.end(), cmp);
    cout << s2;
    return 0;
}
