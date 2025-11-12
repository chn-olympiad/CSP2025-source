#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,a[100010][3],mp[3];
void dfs(int x,int sum)
{
    if(x == n + 1) { ans = max(ans,sum); return; }
    if(mp[0] < n / 2) mp[0] += 1,dfs(x + 1,sum + a[x][0]),mp[0] -= 1;
    if(mp[1] < n / 2) mp[1] += 1,dfs(x + 1,sum + a[x][1]),mp[1] -= 1;
    if(mp[2] < n / 2) mp[2] += 1,dfs(x + 1,sum + a[x][2]),mp[2] -= 1;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
        dfs(1,0);
        cout << ans << endl;
        ans = mp[0] = mp[1] = mp[2] = 0;
    }
    return 0;
}
