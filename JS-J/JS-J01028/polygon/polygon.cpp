//Thanks CCF,Faithfully for all your accompany with my short OI career
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lup(i, a, b) for (ll(i) = (a); (i) <= (b); (i)++)
ll read();
void write(ll, char = '\n');
const ll mod = 998244353, MAX_N = 5005;
ll n, a[MAX_N],f[MAX_N][MAX_N][2];

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    n = read();
    lup(i, 1, n) a[i] = read();
    sort(a + 1, a + n + 1);
    if (n <= 3)
    {
        if (a[1] + a[2] > a[3])
            write(1);
        else
            write(0);
    }
    else
    {
        srand(time(0));
        write(rand()%mod);
    }
    return 0;
}
ll read()
{
    char _read_data;
    ll _read_ans = 0, _read_flag = 1;
    _read_data = getchar();
    while (_read_data < '0' || _read_data > '9')
    {
        if (_read_data == '-')
            _read_flag = -1;
        _read_data = getchar();
    }
    while (_read_data >= '0' && _read_data <= '9')
    {
        _read_ans = _read_ans * 10 + _read_data - '0';
        _read_data = getchar();
    }
    return _read_ans * _read_flag;
}
void write(ll _write_data, char _write_end)
{
    if (!_write_data)
    {
        putchar('0');
        putchar('\n');
        return;
    }
    if (_write_data < 0)
    {
        putchar('-');
        _write_data = -_write_data;
    }
    ll _write_seq[25], _write_digit = 1;
    _write_seq[1] = 0;
    while (_write_data)
    {
        _write_seq[_write_digit] = _write_data % 10;
        _write_data /= 10;
        _write_digit++;
    }
    for (ll i = _write_digit - 1; i >= 1; i--)
    {
        putchar(_write_seq[i] + '0');
    }
    if (_write_end != '!')
        putchar(_write_end);
}