#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a[100010][4];
bool cmp1(int x,int y)
{
    return max(a[x][2],a[x][3]) - a[x][1] > max(a[y][2],a[y][3]) - a[y][1];
}
bool cmp2(int x,int y)
{
    return max(a[x][1],a[x][3]) - a[x][2] > max(a[y][1],a[y][3]) - a[y][2];
}
bool cmp3(int x,int y)
{
    return max(a[x][1],a[x][2]) - a[x][3]> max(a[y][1],a[y][2]) - a[y][3];
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++)
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        vector <int> p[4];
        ll ans = 0;
        for(int i = 1;i <= n;i++)
        {
            ll mx = max(a[i][1],max(a[i][2],a[i][3]));
            ans += mx;
            if(mx == a[i][1])
                p[1].push_back(i);
            else if(mx == a[i][2])
                p[2].push_back(i);
            else
                p[3].push_back(i);
        }
        if(p[1].size() > (n / 2))
        {
            sort(p[1].begin(),p[1].end(),cmp1);
            for(int i = 0;i < p[1].size() - (n / 2);i++)
            {
                ans -= a[p[1][i]][1];
                ans += max(a[p[1][i]][2],a[p[1][i]][3]);
            }
        }
        else if(p[2].size() > (n / 2))
        {
            sort(p[2].begin(),p[2].end(),cmp2);
            for(int i = 0;i < p[2].size() - (n / 2);i++)
            {
                ans -= a[p[2][i]][2];
                ans += max(a[p[2][i]][1],a[p[2][i]][3]);
            }
        }
        else if(p[3].size() > (n / 2))
        {
            sort(p[3].begin(),p[3].end(),cmp3);
            for(int i = 0;i < p[3].size() - (n / 2);i++)
            {
                ans -= a[p[3][i]][3];
                ans += max(a[p[3][i]][1],a[p[3][i]][2]);
            }
        }
        cout << ans << '\n';
    }
}
