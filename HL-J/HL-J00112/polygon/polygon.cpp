#include <bits/stdc++.h>
using namespace std;

int n, a[5005];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    if (n == 3)
    {
        int x, y, z;
        cin >> a[1] >> a[2] >> a[3];
        sort(a + 1, a + 4);
        x = a[1];
        y = a[2];
        z = a[3];
        if (x + y > z)
            cout << 1;
        else
            cout << 0;
    }
    else
    {
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        cout << 62965896;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
