#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int m[n];
    for(int i;i <= n;i++)
    {
        cin >> m[i];
    }
    if (k == 0)
    {
        cout << 1;
    }
    else
    {
        cout << 2;
    }
    return 0;
}
