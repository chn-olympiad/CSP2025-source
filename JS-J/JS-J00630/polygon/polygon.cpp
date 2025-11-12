#include <bits/stdc++.h>
using namespace std;
unsigned long long sum;
unsigned long long mul(int base, int x)
{
    unsigned long long m = 1;
    if(x == 0) return 0;
    for(int i = 1; i <= x; i++)
    {
        m *= base;
        base--;
    }
    return m;
}
int a[1010];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 3; i <= n; i++)
    {
        sum += mul(n, i);
    }
    cout << sum;
    return 0;
}
