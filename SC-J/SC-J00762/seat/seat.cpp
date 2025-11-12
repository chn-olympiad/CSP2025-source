#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen = ("seat.in","r",stdin);
    freopen = ("seat.out","w",stdout);
    double n, m, a[105], c, r;
    cin >> n >> m;
    for (int i=1;i<=n*m;i++){
        cin >> a[i];
    }
    int sum = 0;
    for (int i=2;i<=n*m;i++)
        if (a[1] >= a[i])
            sum++;
    sum++;
    if (sum % n != 0)
        c = sum / n + 1;
    else
        c = sum / n;
    if (c % 2 == 1)
        r = sum % n;
    else
        r = n - sum % n;
    cout << c << " " << r << endl;
    return 0;
}
