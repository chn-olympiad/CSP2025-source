#include<bits/stdc++.h>
using namespace std;
int a[5100],sum[5100],n,ansa;
void dfs(int k,int maxl,int ad,int g)
{
	if(k>n)
	{
		if(maxl*2<ad&&g>2) ansa++;
		ansa=ansa%998244353;
		return;
	}
	dfs(k+1,maxl,ad,g);
	dfs(k+1,a[k],ad+a[k],g+1);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ansa%998244353;
	return 0;
}
