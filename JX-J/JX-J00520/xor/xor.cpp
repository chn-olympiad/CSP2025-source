#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], ans;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]^=a[i-1];
    }
    int sb = 1;
    for (int r = 1; r <= n; r++)
    {
        for (int l = sb; l <= r; l++)
        {
            if ((a[r]^a[l-1]) == k)
            {
                ans++;
                //cout << r << '\n';
                sb = r+1;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
