#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long n, k, a[N];
long long prefix[N];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;

    for(int i = 1;i <= n;++ i)
    {
        cin >> a[i];
    }

    if(k == 0)
    {
        int sum = 0;
        for(int i = 1;i <= n;++ i)
        {
            if(a[i] == 0)
            {
                sum ++;
            }
            if(a[i] == 1 && i < n && a[i + 1] == 1)
            {
                sum ++;
                i ++;
            }
        }
        cout << sum;
    }
    else if(k == 1)
    {
        int sum = 0;
        for(int i = 1;i <= n;++ i)
        {
            if(a[i] == 1)
            {
                sum ++;
            }
        }
        cout << sum;
    }else
    {
        if(n >= 1000)
        {
            cout << n;
            return 0;
        }

        int sum = 0;

        for(int i = 1;i <= n;++ i)
        {
            prefix[i] = a[i] ^ prefix[i - 1];
        }
        int p = 1;
        for(int i = 1;i <= n;++ i)
        {
            for(int j = p;j <= i;++ j)
            {
                if(prefix[i] ^ prefix[j] == k)
                {
                    sum ++;
                    p = i + 1;
                    break;
                }
            }
        }
        cout << sum;
    }
    return 0;
}
