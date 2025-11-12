#include <bits/stdc++.h>
using namespace std;
int n, d[510], l[510], m, s = 0;
int p[510];
const int M = 998244353;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    int a0 = 0;
    int f = 1;
    {
        string t;
        cin >> t;
        for(int i = 0; i < n; i++)
        {
            l[i + 1] = t[i] - '0';
            f &= l[i + 1];
        }
    }

    for(int i = 1; i <= 500; i++)
    {
        p[i] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> d[i];
        if(d[i] == 0)
        {
            a0++;
        }
    }
    if(f)
    {
        if(n - a0 < m)
        {
            cout << 0;
            return 0;
        }
        long long s = 1;
        for(int i = 1; i <= n; i++)
        {
            s *= i;
            s %= M;
        }
        cout << s;
        return 0;
    }
    //next_permutation()
    do
    {
        int t = 0;
        int h = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!l[i])
            {
                h++;
                continue;
            }
            if(h >= d[p[i]])
            {
                h++;
                continue;
            }
            t++;
        }
        if(t >= m)
        {
            s++;
            s %= M;
        }
    }
    while(next_permutation(p + 1, p + n + 1));
    cout << s;
    return 0;
}
