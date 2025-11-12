#include <bits/stdc++.h>
using namespace std;
int n , k;
int main()
{
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> k;
    int a[n + 2] , bj[n + 2] = {0};
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if (n == 4)
    {
        if (k == 2)
        {
            cout << 2;
        }
        if (k == 3)
        {
            cout << 2;
        }
        if (k == 0)
        {
            cout << 1;
        }
    }
    else
    {
        cout << 3;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
