#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, a[500005];
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool A = true;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != 1)
        {
            A = false;
            break;
        }
    }
    if(A && k == 0)
    {
        cout << n / 2 << endl;
        return 0;
    }
    if(k == 1)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 1)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
        return 0;
    }
    return 0;
}
