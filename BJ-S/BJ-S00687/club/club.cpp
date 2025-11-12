#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5;
int a[N + 5][5];
int b[N + 5];
int t1,t2,t3;
int n;

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
        t1 = t2 = t3 = 0;
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            int mx = max(a[i][1],max(a[i][2],a[i][3]));
            if(mx == a[i][1])
            {
                t1++;
                ans += a[i][1];
            }
            else if(mx == a[i][2])
            {
                t2++;
                ans += a[i][2];
            }
            else
            {
                t3++;
                ans += a[i][3];
            }
        }
        if(t1 > n / 2)
        {
            for(int i = 1;i <= n;i++)
            {
                int mx = max(a[i][1],max(a[i][2],a[i][3]));
                if(mx == a[i][1])
                {
                    b[i] = min(a[i][1] - a[i][2],a[i][1] - a[i][3]);
                }
                else
                {
                    b[i] = 9e18;
                }
            }
        }
        else if(t2 > n / 2)
        {
            for(int i = 1;i <= n;i++)
            {
                int mx = max(a[i][1],max(a[i][2],a[i][3]));
                if(mx == a[i][2])
                {
                    b[i] = min(a[i][2] - a[i][1],a[i][2] - a[i][3]);
                }
                else
                {
                    b[i] = 9e18;
                }
            }
        }
        else
        {
            for(int i = 1;i <= n;i++)
            {
                int mx = max(a[i][1],max(a[i][2],a[i][3]));
                if(mx == a[i][3])
                {
                    b[i] = min(a[i][3] - a[i][1],a[i][3] - a[i][2]);
                }
                else
                {
                    b[i] = 9e18;
                }
            }
        }
        if(!(t1 > n / 2 || t2 > n / 2 || t3 > n / 2))
        {
            cout << ans << endl;
            continue;
        }
        sort(b + 1,b + 1 + n);
        int mx = max(t1,max(t2,t3));
        for(int i = 1;i <= mx - n / 2;i++)
        {
            ans -= b[i];
        }
        cout << ans << endl;
    }
    return 0;
}
