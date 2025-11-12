#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int mod=998244353;
struct node{int cnt,sum;}f[5005];
int n,a[5005],ans;
int dis[505][505][505];
void dfs(int step,int maxl,int sum)
{
	if(step>n)
	{
		if(maxl*2<sum)ans++;
		ans%=mod;
		return;
	} 
	dfs(step+1,maxl,sum);
	dfs(step+1,max(maxl,a[step]),sum+a[step]);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)cin >> a[i];
	dfs(1,0,0);
	cout << ans;
	return 0;
} 
