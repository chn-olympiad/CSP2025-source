#include <bits/stdc++.h>
using namespace std;
int T, n;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        int a, b, c;
        int la = 0, lb = 0, lc = 0;
        int las = 0, lbs = 0, lcs = 0;
        char s[3];
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b >> c;
            if (a > b && a > c)
            {
                s[0] = 'a';
                if (b > c)
                    s[1] = 'b', s[2] = 'c';
                else
                    s[1] = 'c', s[2] = 'b';
            }
            if (b > a && b > c)
            {
                s[0] = 'b';
                if (a > c)
                    s[1] = 'a', s[2] = 'c';
                else
                    s[1] = 'c', s[2] = 'a';
            }
            if (c > b && c > a)
            {
                s[0] = 'c';
                if (a > b)
                    s[1] = 'a', s[2] = 'b';
                else
                    s[1] = 'b', s[2] = 'c';
            }
            if (s[0] == 'a')
            {
                if (las < n / 2)
                {
                    las++;
                    la += a;
                }else
                {
                    if (s[1] == 'b' && lbs < n / 2)
                        lbs++, lb += b;
                    else
                        lcs++, lc += c;
                }
            }
            if (s[0] == 'b')
            {
                if (lbs < n / 2)
                {
                    lbs++;
                    lb += b;
                }else
                {
                    if (s[1] == 'a' && las < n / 2)
                        las++, la += b;
                    else
                        lcs++, lc += c;
                }
            }
            if (s[0] == 'c')
            {
                if (lcs < n / 2)
                {
                    lcs++;
                    lc += c;
                }else
                {
                    if (s[1] == 'b' && lbs < n / 2)
                        lbs++, lb += b;
                    else
                        las++, la += a;
                }
            }
        }
        cout << la + lb + lc << endl;
    }
    return 0;
}
