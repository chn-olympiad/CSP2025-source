#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, a[5005];
    long long sum;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n + 1);
    int num;
    num = a[1];
    if(a[1] < a[2])
    {
        num = a[2];
    }

    if(a[1] < a[3])
    {
        num = a[3];
    }
    if((a[1] + a[2] + a[3]) > (n * 2))
    {
        sum++;
    }
    cout << sum %998224353;
    return 0;
}
