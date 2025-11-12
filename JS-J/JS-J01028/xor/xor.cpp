#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lup(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
ll read();
void write(ll, char = '\n');
const ll MAX_N = 500005;
bool _spA = true, _spB = true, _spC = true;
namespace Solve
{
    ll n, k, a[MAX_N];
    void solveA()
    {
        write(n / 2);
    }
    void solveB()
    {
        ll ans = 0;
        if (!k) //k==0
        {
            a[0] = 0;
            lup(i, 1, n)
            {
                if (!a[i])
                    ans++;
                else if (a[i] == 1&&a[i-1]==1)
                {
                    ans++;
                    if(i!=n&&a[i+1]==0)ans++;
                    i++;
                }
            }
        }
        else
            lup(i, 1, n) if (a[i]) ans++;
        write(ans);
    }
    void solveC()
    {
    }
    void solve()
    {
    }
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    Solve::n = read();
    Solve::k = read();
    lup(i, 1, Solve::n)
    {
        Solve::a[i] = read();
        if (Solve::a[i] != 1)
        {
            if (Solve::a[i] != 0)
                _spB = false;
            _spA = false;
        }
        if (Solve::a[i] > 255)
            _spC = false;
    }
    if (_spA)
        Solve::solveA();
    else if (_spB)
        Solve::solveB();
    else if (_spC)
        Solve::solveC();
    else
        Solve::solve();
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