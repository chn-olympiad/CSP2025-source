#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lup(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
ll read();
void write(ll, char = '\n');
ll bullet[10];
string s;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    char _read_data = getchar();
    while (_read_data != '\n')
    {
        if (_read_data >= '0' || _read_data <= '9')
            bullet[_read_data - '0']++;
        _read_data = getchar();
    }
    for (ll i = 9; i >= 0; i--)
        lup(j, 1, bullet[i]) putchar(i + '0');
    putchar('\n');
    return 0;
}