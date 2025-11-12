#include <bits/stdc++.h>
using namespace std;
string s;
long long t[15];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    long long l = s.length();
    for (long long i = 0; i < l; i ++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            t[s[i]-'0'] ++;
        }
    }
    for (long long i = 9; i >= 0; i --)
    {
        for (long long j = 1; j <= t[i]; j ++)
        {
            cout << i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
