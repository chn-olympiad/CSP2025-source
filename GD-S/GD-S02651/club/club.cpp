#include <bits/stdc++.h>
using namespace std;
struct node{
	int d[3];
}a[100005];
bool flag;
int t,n,m,b[3];
long long ans,sum;
void dfs(int i)
{
	if(i>n)
	{
		if(ans<sum)ans=sum;
		return;
	}
	for(int j=0;j<3;++j)
	{
		if(b[j]>=m)continue;
		b[j]++,sum+=a[i].d[j];
		dfs(i+1);
		b[j]--,sum-=a[i].d[j];
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(;t>0;--t)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)scanf("%d",&a[i].d[j]);
		}
		m=n/2,ans=0;
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
