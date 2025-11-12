#include <iostream>
using namespace std;

int a[200010];

int main()
{
    freopen(xor.in, 'r', stdin);
    freopen(xor.out, 'w', stdout);
    int n, k;
    bool A = 1;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] == 0)
        {
            A = 0;
        }
    }
    //FEVrPBDwTolxH
    if(A == 1)
    {
        cout << n / 2;
    }
    else
    {
        if(k == 1)
        {
            int cnt = 0;
            a[0] = 111;
            for(int i = 1;i <= n;i++)
            {
                if(a[i] == 1)
                {
                    cnt++;
                }
            }
            cout << cnt;
        }
        else
        {
            int cnt = 0;
            if(a[1] == 0)
            {
                cnt++;
            }
            for(int i = 2;i <= n;i++)
            {
                if(a[i] == 0)
                {
                    cnt++;
                }
                if(a[i] == 1 && a[i - 1] == 1 && a[i - 2] == 1)
                {
                    cnt++;
                    a[i] = 0;
                }
            }
            cout << cnt;
        }
    }
    return 0;
}
