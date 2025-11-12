#include<bits/stdc++.h>
using namespace std;
const int N=5050,mod=998244353;
int n,a[N],ans;
void dfs(int u,int num,int sum)
{
	if(num>=3)
	{
		if(sum>a[u]*2)
		{
			ans=(ans+1)%mod;
		}
	}
	for(int i=u+1;i<=n;i++)
	{
		dfs(i,num+1,sum+a[i]);
	}
}
int main ()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	printf("%d\n",ans);
	return 0;
}//我喜欢李佳诺