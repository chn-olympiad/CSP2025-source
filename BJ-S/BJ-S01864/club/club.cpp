#include<bits/stdc++.h>
using namespace std;
int v1[100005], v2[100005], v3[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int ans = 0;
        v1[0] = v2[0] = v3[0] = 0;
        for(int i = 1;i <= n;i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            int mx = max(a, max(b, c));
            ans += mx;
            int mn = min(a, min(b, c));
            if(a >= b && a >= c)
            {
                v1[++v1[0]] = mx + mx + mn - a - b - c;
                continue;
            }
            if(b >= a && b >= c)
            {
                v2[++v2[0]] = mx + mx + mn - a - b - c;
                continue;
            }
            if(c >= a && c >= b)
            {
                v3[++v3[0]] = mx + mx + mn - a - b - c;
                continue;
            }
        }
        if(v1[0] > (n / 2))
        {
            sort(v1 + 1, v1 + 1 + v1[0]);
            for(int i = 1;i <= v1[0] - (n / 2);i++) ans -= v1[i];
            cout << ans << endl;
            continue;
        }
        if(v2[0] > (n / 2))
        {
            sort(v2 + 1, v2 + 1 + v2[0]);
            for(int i = 1;i <= v2[0] - (n / 2);i++) ans -= v2[i];
            cout << ans << endl;
            continue;
        }
        if(v3[0] > (n / 2))
        {
            sort(v3 + 1, v3 + 1 + v3[0]);
            for(int i = 1;i <= v3[0] - (n / 2);i++) ans -= v3[i];
            cout << ans << endl;
            continue;
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}
