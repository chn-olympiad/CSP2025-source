#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y)
{
    return x >y;
}

vector<int> s;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n*m ; i++)
    {
        int a;
        cin >> a;
        s.push_back(a);
    }
    int a1 = s[0];

    sort(s.begin(), s.end(), cmp);
    int pm;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == a1)
        {
            pm = i + 1; break;
        }
    int line, row;
    if (pm % m != 0) line = pm / n + 1;
    else line = pm / n;

    if (line % 2 == 1)
    {
        row = pm % m;
    }
    else
    {
        row = n+1 - (pm % m);
    }

    cout << line <<' ';
    if (row == 0) cout <<m <<'\n';
    else cout << row<<'\n';
    return 0;
}
