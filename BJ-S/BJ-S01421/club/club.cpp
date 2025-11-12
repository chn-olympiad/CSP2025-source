#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stu
{
    ll x;
    bool f;
};
stu a[10][100010];
int temp[100010];
int main()
{
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        int cnt1 = 0 , cnt2 = 0 , cnt3 = 0;
        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[1][i].x >> a[2][i].x >> a[3][i].x;
            a[1][i].f = a[2][i].f = a[3][i].f = 0;
            if(a[1][i].x >= a[2][i].x && a[1][i].x >= a[3][i].x)
            {
                cnt1 ++;
                a[1][i].f = 1;
                ans += a[1][i].x;
            }
            else if(a[2][i].x >= a[1][i].x && a[2][i].x >= a[3][i].x)
            {
                cnt2 ++;
                a[2][i].f = 1;
                ans += a[2][i].x;
            }
            else if(a[3][i].x >= a[1][i].x && a[3][i].x >= a[2][i].x)
            {
                cnt3 ++;
                a[3][i].f = 1;
                ans += a[3][i].x;
            }
        }
        memset(temp , 0 , sizeof(temp));
        int cur = 0;
        if(cnt1 > n / 2)
        {
            for(int i = 1; i <= n; i++)
            {
                if(a[1][i].f == 1)
                {
                    temp[++ cur] = min(a[1][i].x - a[2][i].x , a[1][i].x - a[3][i].x);

                }
            }
            sort(temp + 1 , temp + cur + 1);
            for(int i = 1; i <= cnt1 - n / 2; i++) ans -= temp[i];
            cout << ans << endl;
        }
        else if(cnt2 > n / 2)
        {
            for(int i = 1; i <= n; i++)
            {
                if(a[2][i].f == 1)
                {
                    temp[++ cur] = min(a[2][i].x - a[1][i].x , a[2][i].x - a[3][i].x);
                }
            }
            sort(temp + 1 , temp + cur + 1);
            for(int i = 1; i <= cnt2 - n / 2; i++) ans -= temp[i];
            cout << ans << endl;
        }
        else if(cnt3 > n / 2)
        {
            for(int i = 1; i <= n; i++)
            {
                if(a[3][i].f == 1)
                {
                    temp[++ cur] = min(a[3][i].x - a[1][i].x , a[3][i].x - a[2][i].x);
                }
            }
            sort(temp + 1 , temp + cur + 1);
            for(int i = 1; i <= cnt3 - n / 2; i++) ans -= temp[i];
            cout << ans << endl;
        }
        else cout << ans << endl;
    }
    return 0;
}
