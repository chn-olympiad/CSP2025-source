#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int a[N];
int n;

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    int res = 0;
    for (int i = 1; i < 1 << n; i ++ )
    {
        int num = -1, sum = 0;
        for (int j = 0; i >= (1 << j); j ++ )
            if ((i >> j) & 1)
                sum += a[j], num = max(num, a[j]);
        if (sum > 2 * num)
            res ++ ;
    }

    cout << res << endl;

    return 0;
}
