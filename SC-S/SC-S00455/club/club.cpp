#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,mp[N][5],vis[N],ans,tem[N],a,b,c,maxx;
void check(int kd)
{
	vector<pair<int,int> > jg;
	for(int i=1;i<=n;i++)
	{
		jg.push_back({mp[i][kd],i});
	}
	sort(jg.begin(),jg.end());
	for(int i=n-1;i>=0;i--)
	{
		int maxn=0;
		ans-=jg[i].first;
		if(kd==1) a--;
		if(kd==2) b--;
		if(kd==3) c--;
		for(int j=kd;j<=n;j++)
		{
			if(j==kd) continue;
			if(mp[i][j]>maxn)
			{
				tem[i]=j;
				maxn=mp[i][j];
			}
		}
		if(tem[i]==1)
		{
			a++;
			ans+=maxn;
		}
		if(tem[i]==2)
		{
			b++;
			ans+=maxn;
		}
		if(tem[i]==3)
		{
			c++;
			ans+=maxn;
		}
		if(a<=n/2&&b<=n/2&&c<=n/2)
		{
			break;
		}
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1,x;j<=3;j++)
			{
				scanf("%lld",&mp[i][j]);
			}
		}
		a=0;b=0;c=0;maxx=n/2;
		for(int i=1;i<=n;i++)
		{
			int maxn=0;
			for(int j=1;j<=n;j++)
			{
				if(mp[i][j]>maxn)
				{
					tem[i]=j;
					maxn=mp[i][j];
				}
			}
			if(tem[i]==1)
			{
				a++;
				ans+=maxn;
			}
			if(tem[i]==2)
			{
				b++;
				ans+=maxn;
			}
			if(tem[i]==3)
			{
				c++;
				ans+=maxn;
			}
		}
		if(a<=maxx&&b<=maxx&&c<=maxx)
		{
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
		else
		{
			check(1);
			if(a<=maxx&&b<=maxx&&c<=maxx)
			{
				cout<<ans<<'\n';
				continue;
			}
			check(2);
			if(a<=maxx&&b<=maxx&&c<=maxx)
			{
				cout<<ans<<'\n';
				continue;
			}
			check(3);
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/