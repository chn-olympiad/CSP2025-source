#include <bits/stdc++.h>
using namespace std;

int n, k, a[500005][30];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    if(n==1){
        int x;
        cin>>x;
        cout<<x<<endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int m = 0, q = 1, p = 0;
        while (q <= x)
        {
            q *= 2;
            m++;
        }

        for (int j = m; j >= 1; j--)
        {
            if (q < p)
            {
                p -= q;
                a[i][j] = 1;
            }
            q /= 2;
        }
    }
    return 0;
}