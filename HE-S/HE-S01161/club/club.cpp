#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[100001][5],peos[5];
ll ans=0;
void f(int s,ll tmp)
{
	if(s>n)
	{
		ans=max(tmp,ans);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(peos[i]+1<=n/2)
		{
			int now=tmp+a[s][i];
			peos[i]++;
			f(s+1,now);
			peos[i]--;
		}
	}
}
inline void solve()
{
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	f(1,0);
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
