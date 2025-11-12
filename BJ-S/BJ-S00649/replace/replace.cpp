#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int N = 2e5 + 5;
int n, q, ans, ls, rs, l[N], r[N], L1;
bool flag;
string s[5][N], t[5];
map <int, int> mp;

void solve1()
{
    //for(int q = 1;q <= 20;q++)
    while(q--)
    {
        cin >> t[1] >> t[2];
        t[1] = "#" + t[1], t[2] = "#" + t[2], ans = 0;
        ls = 1, rs = t[1].size() - 1;
        while(ls < rs && t[1][ls] == t[2][ls])  ls++;
        while(ls < rs && t[1][rs] == t[2][rs])  rs--;
        //printf("%d %d\n", ls, rs);
        for(int i = 1;i <= n;i++)
        {
            if(rs - ls != r[i] - l[i])  continue;
            if(l[i] > ls || s[1][i].size() - r[i] > t[1].size() - rs)   continue;
            //printf("%d\n", i);
            flag = true;
            for(int sl = 1, tl = ls - l[i] + 1;sl < s[1][i].size();sl++, tl++)
            {
                if(s[1][i][sl] != t[1][tl] || s[2][i][sl] != t[2][tl])  flag = false;
                //printf("%d %d\n", sl, tl);
            }
            if(flag)    ans++;
        }
        printf("%d\n", ans);
    }
}

void solve2()
{
    for(int i = 1;i <= n;i++)
    {
        if(s[1][i][l[i]] == s[2][i][l[i]])  continue;
        if(s[1][i][l[i]] == 'b')
            mp[r[i] - l[i]]++;
        else
            mp[l[i] - r[i]]++;
    }
    while(q--)
    {
        cin >> t[1] >> t[2];
        t[1] = "#" + t[1], t[2] = "#" + t[2], ans = 0;
        ls = 1, rs = t[1].size() - 1;
        while(ls < rs && t[1][ls] == t[2][ls])  ls++;
        while(ls < rs && t[1][rs] == t[2][rs])  rs--;
        if(t[1][ls] == 'b')
            printf("%d\n", mp[rs - ls]);
        else
            printf("%d\n", mp[ls - rs]);
    }
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d %d", &n, &q);
    //printf("%d %d\n", n, q);
    for(int i = 1;i <= n;i++)
    {
        cin >> s[1][i] >> s[2][i];
        L1 += s[1][i].size();
        s[1][i] = "#" + s[1][i], s[2][i] = "#" + s[2][i];
        l[i] = 1, r[i] = s[1][i].size() - 1;
        //cout << s[1][i] << " " << s[2][i] << endl;
        while(l[i] < r[i] && s[1][i][l[i]] == s[2][i][l[i]])  l[i]++;
        while(l[i] < r[i] && s[1][i][r[i]] == s[2][i][r[i]])  r[i]--;
        //printf("%d %d\n", l[i], r[i]);
    }
    //cout << s[1][3] << " " << s[1][4] << endl;
    if(L1 * q <= 5e6)   solve1();
    else    solve2();
    return 0;
}
