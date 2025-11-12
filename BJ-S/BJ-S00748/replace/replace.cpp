#include <bits/stdc++.h>
using namespace std;

string olds[200010], news[200010], sold, snew;

int cnt, n, q;

bool check(string s, string snew)
{
    if(s.size() != snew.size()) return 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != snew[i]) return 0;
    }
    return 1;
}

void dfs(int step, string snow)
{
    if(step > n)
    {
        if(check(snow, snew))
        {
            cnt++;
        }
        return;
    }
    if(olds[step].size() <= snow.size())
    {
        string s = snow;
        for(int i = 0; i < s.size() - olds[step].size() + 1; i++)
        {
            if(s[i] == olds[step][0])
            {
                if(check(s.substr(i, olds[step].size()), olds[step]))
                {
                    dfs(step + 1, s.substr(0, i) + news[step] + s.substr(i + olds[step].size()));
                }
            }
        }
    }
    dfs(step + 1, snow);
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> olds[i] >> news[i];
    }
    for(int i = 1; i <= q; i++)
    {
        cnt = 0;
        cin >> sold >> snew;
        if(sold.size() == snew.size()) dfs(1, sold);
        cout << cnt << endl;
    }
    return 0;
}
