#include <bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
void dfs(int x,int l,int m)
{
	if(x>n) return;
	if(x>=3 and l>2*m) ans=(ans+1)%998244353;
	for(int i=x+1;i<=n;i++)
	{
		dfs(i,l+a[i],max(m,a[i]));
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(0,0,0);
	printf("%d",ans);
	return 0;
}