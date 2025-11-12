#include<iostream>
#include<string>
#include<map>

using namespace std;
using Str = string;

const int Potata = 2e5 + 5;

int n, q;
Str s1[Potata], s2[Potata];

bool sp[Potata];
int idx1[Potata], idx2[Potata];
int length[Potata];
int diff[Potata];

int difference(int idx)
{
    if (s1[idx] == s2[idx])
            return 0;

    int left, right;

    for (int i = 0; i < length[idx]; i++)
        if (s1[idx][i] != s2[idx][i])
            { left = i; break; }

    for (int i = length[idx] - 1; i >= 0; i--)
        if (s1[idx][i] != s2[idx][i])
            { right = i; break; }

    return right - left + 1;
}

bool special(Str str, int len)
{
    int cnt = 0;
    for (int i = 0; i < len; i++)
        if (str[i] == 'b')
            cnt++;
        else if (str[i] != 'a')
            return false;

    return (cnt == 1);
}

int findB(Str str, int len)
{
    for (int i = 0; i < len; i++)
        if (str[i] == 'b')
            return i;
}

bool forAll(int idx)
{
    int len = length[idx];
    string tmp = s1[0];

    for (int i = 0; i < length[0] - len + 1; i++)
    {
        if (s1[0].substr(i, len) == s1[idx])
        {
            for (int j = 0; j < len; j++)
                tmp[i + j] = s2[idx][j];
        }
    }

    return (tmp == s2[0]);
}

bool forB(int idx)
{
    int cur = idx1[0];
    int dist = idx2[idx] - idx1[idx];
    int nxt = idx2[0];

    int left1 = idx1[0], right1 = length[0] - idx1[0] - 1;
    int left2 = idx1[idx], right2 = length[idx] - idx1[idx] - 1;

    bool flg1 = (cur + dist == nxt);
    bool flg2 = ((left1 >= left2) && (right1 >= right2));

    return (flg1 && flg2);
}

void solve()
{
    cin >> s1[0] >> s2[0];
    length[0] = s1[0].size();
    diff[0] = difference(0);
    sp[0] = (special(s1[0], length[0]) && special(s2[0], length[0]));
    idx1[0] = findB(s1[0], length[0]), idx2[0] = findB(s2[0], length[0]);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (diff[0] > diff[i])
            continue;
        else if (sp[i] && sp[0])
            ans += forB(i);
        else
            ans += forAll(i);

    cout << ans << '\n';
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> s1[i] >> s2[i],
        length[i] = s1[i].size(),
        diff[i] = difference(i),
        sp[i] = (special(s1[i], length[i]) && special(s2[i], length[i]));

    for (int i = 1; i <= n; i++)
        if (sp[i])
            idx1[i] = findB(s1[i], length[i]),
            idx2[i] = findB(s2[i], length[i]);

    while (q--)
        solve();

    return 0;
}
