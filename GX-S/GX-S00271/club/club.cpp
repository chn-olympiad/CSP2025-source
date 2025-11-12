#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 114514;
inline void solve()
{
    int a[maxn][4],n;
    vector<int>replacement;
    ll ans=0;
    int nummax[4]= {0};
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> a[i][j];
        }
        int m=max({a[i][1],a[i][2],a[i][3]});
        ans+=m;
        if(m == a[i][1])
        {
            nummax[1]++;
        }
        else if(m== a[i][2])
        {
            nummax[2]++;
        }
        else
        {
            nummax[3]++;
        }
    }
    int m=max({nummax[1],nummax[2],nummax[3]});
    int max1,max2,max3;
    if(m==nummax[1])
    {
        max1=1,max2=2,max3=3;
    }
    if(m==nummax[2])
    {
        max1=2,max2=1,max3=3;
    }
    if(m==nummax[3])
    {
        max1=3,max2=1,max3=2;
    }
    for(int i = 1; i <= n; i++)
    {
        if(max({a[i][1],a[i][2],a[i][3]})==a[i][max1])
            replacement.push_back(min(a[i][max1]-a[i][max2],a[i][max1]-a[i][max3]));
    }
    sort(replacement.begin(),replacement.end());
    for(int i = 0; i < nummax[max1]-(n/2); i++)
    {
        ans-=replacement[i];
    }
    cout << ans << '\n';
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
