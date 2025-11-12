#include <bits/stdc++.h>
using namespace std;
int n,k;
const int N = 5e5 + 5;
int a[N];
bool f[N];
struct Possible
{
    int fir,las,cha;
} x[N];
int zsy(int i, int j)
{
    if (i == j) return a[i];
    return a[i] ^ zsy(i + 1,j);
}
bool cmp(Possible a, Possible b)
{
    return a.cha < b.cha;
}
bool ok(Possible c)
{
    for (int i = c.fir; i <= c.las; i++)
    {
        if (f[i] == true) return false;
    }
    return true;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int pos = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (zsy(i,j) == k)
            {
                pos++;
                x[pos].fir = i;
                x[pos].las = j;
                x[pos].cha = (x[pos].las - x[pos].fir + 1);
            }
        }
    }
    long long ans = 0;
    sort(x + 1, x + pos + 1,cmp);
    for (int i = 1; i <= pos; i++)
    {
        if (ok(x[i]))
        {
            for (int j = x[i].fir; j <= x[i].las; j++) f[j] = true;
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}
