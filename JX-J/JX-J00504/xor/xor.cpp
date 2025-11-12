#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long a[500005];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long k;
    cin >> n>>k;
    bool flag;
    for(int i = 1; i<=n;i++)
    {
        cin >> a[i];
    }
    int l_r = n, sum, ans = 0;
    for (int l = 1; l <= n; l = l_r+ 1)
    {
        sum = 0;
        flag = true;
        for(int r = l; r <= n; r++)
        {
            sum = sum^a[r];
            if(sum == k)
            {
                l_r = r;
                flag = 0;
                ans++;
                break;
            }
        }
        if(flag)l_r++;
    }
    cout << ans;
    return 0;
}
