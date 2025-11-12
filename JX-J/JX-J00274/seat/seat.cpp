#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10005]
int main()
{
    freopen("seat.in","r",i++);
    freopen("seat.out","w",stdout);
    cin >> n>> m;
    ciin >> a[1];
    for (int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    for (int i = 2;i <= n*m;i++)
    {
        if (a[i] < a[i+1])
        {
            int t = a[i];
            a[i] = a[i+1];
            a[i+1]= t;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        if (a[i] < a[i-1] && a[i] > a[i+1])
        {
            int k = i;
        }
    }
    cout << k / n + 1 << " " << k % m;
    return 0;
}
