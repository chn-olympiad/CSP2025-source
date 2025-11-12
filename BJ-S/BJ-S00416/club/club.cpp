#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int n;
        cin >> n;
        int ans = 0;
        int a1[100005],a2[100005],a3[100005];
        for(int j = 1;j <= n;j++)
        {
            cin >> a1[i]>>a2[i]>>a3[i];
            if(a1[i] > a2[i] && a1[i] > a3[i])
            {
                ans += a1[i];
            }
            else if(a2[i] > a1[i] && a2[i] > a3[i])
            {
                ans += a2[i];
            }
            else
            {
                ans += a3[i];
            }
        }
        cout << ans;
    }
    return 0;
}
