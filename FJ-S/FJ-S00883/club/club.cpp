#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	ll y,e,s;
	const bool operator <(const point &k)const
	{
		return y>k.y;
	}
}a[100005];
int T,n;
ll ans;
void dfs(ll step,ll yi,ll er,ll sa,ll my)
{
	if (step>n)
	{
		ans=max(ans,my);
		return;
	}
	if (yi+1<=n/2)
	{
//		printf("step:%lld 1:%lld 2:%lld 3:%lld my:%lld\n",step,yi+1,er,sa,my+a[step][1]);
		dfs(step+1,yi+1,er,sa,my+a[step].y);
	}
	if (er+1<=n/2)
	{
//		printf("step:%lld 1:%lld 2:%lld 3:%lld my:%lld\n",step,yi,er+1,sa,my+a[step][2]);
		dfs(step+1,yi,er+1,sa,my+a[step].e);
	}
	if (sa+1<=n/2)
	{
//		printf("step:%lld 1:%lld 2:%lld 3:%lld my:%lld\n",step,yi,er,sa+1,my+a[step][3]);
		dfs(step+1,yi,er,sa+1,my+a[step].s); 
	}
}
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%lld%lld%lld",&a[i].y,&a[i].e,&a[i].s);
		if (n>200 && !a[1].e)
		{
			sort(a+1,a+n+1);
			for (ll i=1;i<=n/2;i++)
				ans+=a[i].y;
			printf("%lld\n",ans);
			ans=0;
			continue;
		}
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
	}

