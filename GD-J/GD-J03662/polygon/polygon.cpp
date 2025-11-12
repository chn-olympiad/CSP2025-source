#include <cstdio>
#include <algorithm>
using namespace std;
int n,ans = 0;
int a[5005];
bool vis[5005];
const int MOD = 998244353;
void dfs(int pos,int sum,int mx,int cnt)
{
	if(cnt >= 3 && sum > (mx * 2))
	{
		ans = (ans + 1) % MOD;
	}
	if(pos > n) return ;

	//vis[a[pos]] = true;
	dfs(pos + 1,sum + a[pos],max(mx,a[pos]),cnt + 1);

	//vis[a[pos]] = false;
	dfs(pos + 1,sum,mx,cnt);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	dfs(1,0,-10,0);
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
