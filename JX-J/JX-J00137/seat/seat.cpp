#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, s[105], sum, num, a[105], b = 1;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
    {
        cin >> s[i];
        if(i == 1)
        {
            sum = s[i];
        }
    }
    sort(s, s + n * m + 1);
    for(int i = n * m; i >= 1; i--)
    {
        a[b] = s[i];
        b++;
    }
    for(int i = 1; i <= n * m; i++)
    {
        if(a[i] == sum)
        {
            num = i;
        }
    }
    int c, d;
    if(num % m != 0)
    {
        c = num / m + 1;
        d = num % m;
    }
    else
    {
        c = num / m;
        d = m;
    }
    cout << c << " " << d;
    return 0;
}
