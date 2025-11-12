#include<bits/stdc++.h>
using namespace std;
int a[5010], b[5010];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, ans = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 3; i <= n; i++)
    {
        int maxn = 0, cnt = 0;
        for(int j = 1; j <= i; j++) b[j] = j;
        while(b[1] > n-i)
        {
            for(int j = 1; j <= i; j++)
            {
                cnt += a[b[i]];
                maxn = max(maxn, a[b[i]]);
            }
            if(cnt > 2*maxn) ans++;
            for(int j = i; j >= 1; j--)
            {
                if(b[j] != n-i+j)
                {
                    b[j]++;
                    for(int k = b[j]+1; k <= i; k++) b[++j] = k;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
