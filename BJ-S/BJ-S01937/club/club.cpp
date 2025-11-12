#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t,n,ans;
int a[maxn][5],dp[maxn][5];
void dfs(int now,int sat,int x,int y,int z)
{
    //cout << now << " " << sat << " " << x << " " << y << " " << z << endl;
	if(now > n)
	{
		ans = max(ans,sat);
		return;
	}
	if(x > 0) dfs(now + 1,sat + a[now][1],x - 1,y,z);
	if(y > 0) dfs(now + 1,sat + a[now][2],x,y - 1,z);
	if(z > 0) dfs(now + 1,sat + a[now][3],x,y,z - 1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        dfs(2,a[1][1],n / 2 - 1,n / 2,n / 2);
        dfs(2,a[1][2],n / 2,n / 2 - 1,n / 2);
        dfs(2,a[1][3],n / 2,n / 2,n / 2 - 1);
        cout << ans << endl;
    }
    return 0;
}
