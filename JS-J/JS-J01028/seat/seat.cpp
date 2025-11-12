#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lup(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
ll read();
void write(ll, char = '\n');
ll n, m, c, r, a[105], pos;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    n = read();
    m = read();
    lup(i, 1, n * m) a[i] = read();
    sort(a + 2, a + n * m);
    pos = lower_bound(a + 2, a + n * m, a[1]) - a;
    pos = n * m - pos + 1;
    c = pos / n;
    if (pos % n)
    {
        if (c & 1)
            r = m + c * n - pos + 1;
        else
            r = pos - c * n;
        c++;
    }
    else
        r = (c & 1) ? m : 1;
    write(c, ' ');
    write(r);
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
    if (_write_data==0)
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