#include<bits/stdc++.h>

using namespace std;

char s[510];
int c[510];

bool chea;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        if(s[i] != 1)
        {
            chea = true;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    if(chea == false)
    {
        int a1 = n;
        int c1 = m;

        for(int i = 1; i < m; i++)
        {
            a1 = a1 * (n - 1) % 998244353;
            n--;
        }

        for(int i = 1; i < m; i++)
        {
            c1 = c1 * (m - 1) % 998244353;
            m--;
        }

        cout << a1 / c1 % 998244353;
    }

    return 0;
}

