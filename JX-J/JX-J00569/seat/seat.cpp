#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    int n,m,a[1005],b[1005],q,p;
    cin >> n >> m;
    p = n * m;
    for (int i = 1;i <= p;i++)
    {
        cin >> a[i];
    }
    q = a[1];
    sort (a + 1;p + a + 1);
    for (int i = 0;i < p;i++)
    {
        b[i] = a[p-i];
    }
    for (int i = 0;i < p;i++)
    {
        a[i+1] = b[i];
    }
    for (int i = 1;i <= p;i++)
    {
        if (a[i] == q)
        {
            if ((i / n == 1)&&(i % n == 0))
            {
                cout << 1 << " ";
                cout << i;
            }
            else
            {
                if (i % n == 0)
                {
                    int jojo = i / n;
                    cout << jojo << " ";
                    cout << n;
                }

                else
                {
                    int jojo = i / n;
                    jojo++;
                    cout << jojo << " ";
                    jojo = i - (n * (i/n));
                    cout << jojo;
                }
            }
        }
    }
    return 0;
}
