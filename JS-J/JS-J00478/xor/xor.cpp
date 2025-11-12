#include <bits/stdc++.h>
using namespace std;

int a[100010],n,k,flaga,flagb;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] != 1)
        {
            flaga = 1;
        }
        if(a[i] > 1)
        {
            flagb = 1;
        }
    }
    if(!flaga)
    {
        if(k == 0)
        {
            cout << (n / 2) << "\n";
        }
        else
        {
            cout << n << "\n";
        }
        return 0;
    }
    if(!flagb)
    {
        if(k == 0)
        {
            int cnta = 0,cntb = 0;
            for(int i = 1;i <= n;i++)
            {
                if(a[i])
                {
                    cnta++;
                }
                else
                {
                    cntb++;
                }
            }
            cout << cnta / 2 + cntb << "\n";
        }
        else
        {
            int cnta = 0;
            for(int i = 1;i <= n;i++)
            {
                if(a[i])
                {
                    cnta++;
                }
            }
            cout << cnta << "\n";
        }
        return 0;
    }
    cout << 0 << "\n";
    return 0;
}
