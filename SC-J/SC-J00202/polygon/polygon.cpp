#include<iostream>
using namespace std;
#define int long long
int a[100005],ans=0;
int n;
const int danbo=998244353;
void dfs(int shang,int now,int maxn,int he)
{
	if (now==0)
	{
		if (he>(maxn<<1))
		{
			ans++;
			ans=ans%danbo;
		}
		return ;
	}
	for (int i=shang+1;i<=n-now+1;i++)
	{
		dfs(i,now-1,max(maxn,a[i]),he+a[i]);
	}
	return ;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for (int i=3;i<=n;i++) dfs(0,i,0,0);
	cout<<ans;
	return 0;
}