#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a;i <= b;i++)
typedef long long ll;
const int Max = 5e5+5;
ll read()
{
    int f = 1;
    ll x = 0;
    char c;
    c = getchar();
    while(!isdigit(c)&&c == '-')f = -1, c = getchar();
    while(isdigit(c))x *= 10, x += c-'0', c = getchar();
    return x;
}
ll write(ll x)
{
    if(x < 0)
    {
        putchar('-');
        x = -x;
        write(x);
    }
    else if(x > 9)
    {
        write(x/10);
        putchar(x%10+'0');
    }
    else putchar(x+'0');
}
ll a[Max], n, k;
map<ll, int> mp;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    n = read(), k = read();
    rep(i, 1, n)a[i] = read();
    ll last = -2, res = 0, ans = 0;
    mp[k] = -1;
    rep(i, 1, n)
    {
        res ^= a[i];
        if(mp[res]&&mp[res] > last)
        {
            last = i;
            ans++;
        }
        mp[res^k] = i+1;
    }
    write(ans);
    return 0;
}
