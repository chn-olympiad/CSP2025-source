#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+100,M=2e6+5;
int n,m,k,ctl;
struct line
{
	int f,t,d;
	bool operator<(line y)
	const{
		return d<y.d;
	}
};
vector<pair<int,int>>ma[N];
line li[M];
int fa[N],c[N];
int gtf(int x)
{
	if(fa[x]==x)return x;
	int t=gtf(fa[x]);
	fa[x]=t;
	return t;
}
void push(int x,int y)
{
	int fx=gtf(x),fy=gtf(y);
	fa[fy]=fx;
}
bool lt(int x,int y)
{
	return gtf(x)==gtf(y);
}
int work1()
{
	int ans=0;
	sort(li,li+ctl);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0;i<ctl;i++)
	{
		//printf("%lld %lld %lld\n",li[i].f,li[i].t,li[i].d);
		if(!lt(li[i].f,li[i].t))
		{
			push(li[i].f,li[i].t);
			ans+=li[i].d;
		}
	}
	return ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0;i<m;i++)
	{
		cin>>li[i].f>>li[i].t>>li[i].d;
		ma[li[i].f].push_back({li[i].t,li[i].d});
		ma[li[i].t].push_back({li[i].f,li[i].d});
	}
	if(k==0)
	{
		cout<<work1();
		return 0;
	}
	int th;
	for(int i=n+1;i<=k+n;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>th;
			ma[i].push_back({j,th});
		}
	}
	int ans=1e18,sum;
	for(int i=0;i<(1<<k);i++)
	{
		if(n>1e5&&i!=(1<<k)-1)continue;
		ctl=0;
		for(int i=1;i<=n;i++)
		{
			for(auto x:ma[i])
			{
				if(i<x.first)
				{
					li[ctl].f=i;
					li[ctl].t=x.first;
					li[ctl].d=x.second;
					ctl++;
				}
			}
		}
		sum=0;
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				//cout<<n+j<<"_";
				sum+=c[n+j];
				for(auto x:ma[n+j])
				{
					li[ctl].f=j+n;
					li[ctl].t=x.first;
					li[ctl].d=x.second;
					ctl++;
				}
			}
		}
		ans=min(ans,sum+work1());
		//cout<<i<<"\n";
	}
	cout<<ans;
	return 0;
}
