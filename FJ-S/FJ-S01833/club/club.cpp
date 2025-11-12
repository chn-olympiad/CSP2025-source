#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
priority_queue<pair<int,int> >la,lb,lc;
int T,n;
int maxn,sum,a,b,c;
int l[N][4];
void init()
{
	sum=0;a=0;b=0;c=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&l[i][1],&l[i][2],&l[i][3]);
	for(int i=1;i<=n;i++)
	{
		if(l[i][1]>=l[i][2]&&l[i][1]>=l[i][3])
		{
			la.push({-l[i][1]+max(l[i][2],l[i][3]),i});
			a++;
		}
		else if(l[i][2]>=l[i][1]&&l[i][2]>=l[i][3])
		{
			lb.push({-l[i][2]+max(l[i][1],l[i][3]),i});
			b++;
		}
		else
		{
			lc.push({-l[i][3]+max(l[i][2],l[i][1]),i});
			c++;
		}
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,x,y;
	scanf("%lld",&T);
	while(T--)
	{
		init();
		while(a>n/2)
		{
			x=-1*la.top().first;y=la.top().second;
			la.pop();a--;
			if(l[y][2]>l[y][3])lb.push({-l[y][2]+l[y][3],y});
			else lc.push({-l[y][3]+l[y][2],y});
		}
		while(b>n/2)
		{
			x=-1*lb.top().first;y=lb.top().second;
			lb.pop();b--;
			if(l[y][1]>l[y][3])la.push({-l[y][1]+l[y][3],y});
			else lc.push({-l[y][3]+l[y][1],y});
		}
		while(c>n/2)
		{
			x=-1*lc.top().first;y=lc.top().second;
			lc.pop();c--;
			if(l[y][1]>l[y][2])la.push({-l[y][1]+l[y][2],y});
			else lb.push({-l[y][2]+l[y][1],y});
		}
		while(!la.empty())
		{
			sum+=l[la.top().second][1];
			la.pop();
		}
		while(!lb.empty())
		{
			sum+=l[lb.top().second][2];
			lb.pop();
		}
		while(!lc.empty())
		{
			sum+=l[lc.top().second][3];
			lc.pop();
		}
		printf("%lld\n",sum);
	}
	return 0;
}
