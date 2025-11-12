# include <bits/stdc++.h>

using namespace std;

int cnt[20];

string s;

int main ()
{
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    bool flg = 1;
    cin >> s;
    for (int i = 0; i < s.size (); i++)
    {
        if (isdigit (s[i]))
        {
            if (s[i] != '0') { flg = 0; }
            cnt[s[i] - '0'] ++;
        }
    }

    if (flg)
    {
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 9; i >= 0; i--)
    {
        for (int j = 1; j <= cnt[i]; j++)
        {
            cout << i;
        }
    }
    cout << "\n";

    return 0;
}