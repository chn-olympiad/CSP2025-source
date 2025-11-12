#include<bits/stdc++.h>
using namespace std;
int aa[50010],z,a;
void dfs(int b,int c,int d,int e)
{
	if(b==a+1)
	{
		if(d>e*2) z=(z+1)%998244353;
		return;
	}
	dfs(b+1,c-1,d+aa[b],max(e,aa[b]));
	if(a-b>=c) dfs(b+1,c,d,e);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&aa[i]);
	dfs(1,3,0,0);
	printf("%d",z);
	return 0;
}
