#include<bits/stdc++.h>
#define pii pair<int,int>
#define allof(o) (o).begin(),(o).end()
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int f[10025];
int Find(int x){return f[x]==x?x:f[x]=Find(f[x]);}
struct edge
{
	int x,y,z;
	friend bool operator<(const edge &a,const edge &b)
	{
		return a.z<b.z;
	}
};
struct town
{
	int x;
	vector<int> v;
}t[15];
vector<edge> e,st;
long long ans;
int n,m,k;
void zxscs()
{
	ans=0;
	iota(f+1,f+n+k+1,1);
	sort(allof(e));
	for(auto p:e)
	{
		int x=p.x,y=p.y,z=p.z;
		if(Find(x)==Find(y))continue;
// cerr<<x<<" "<<y<<" "<<z<<'\n';
		f[Find(x)]=Find(y);
		ans+=z;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	while(m--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		e.push_back({x,y,z});
	}
	st=e;
	if(!k)
	{
		zxscs();
		cout<<ans;
		return 0;
	}
	int tsxz_A=1;
	for(int i=1;i<=k;i++)
	{
		cin>>t[i].x;
		if(t[i].x)tsxz_A=0;
		int flag=0;
		for(int j=1;j<=n;j++)
		{
			int y;
			cin>>y;
			t[i].v.push_back(y);
			if(!y)flag=1;
		}
		tsxz_A&=flag;
	}
	if(tsxz_A)
	{
		for(int i=1;i<=k;i++)
		{
			vector<pii> v1;
			vector<int> v2;
			for(int j=0;j<n;j++)
				if(t[i].v[j])
					v1.push_back({j+1,t[i].v[j]});
				else
					v2.push_back(j+1);
			for(int j=1;j<v2.size();j++)
				f[Find(v2[j-1])]=Find(v2[j]);
			for(auto x:v1)
				e.push_back({v2[0],x.first,x.second});
		}
		zxscs();
		cout<<ans;
		return 0;
	}
	long long aans=LONG_LONG_MAX;
	for(int s=(1<<k)-1;s>=0;s--)
	{
		int res=0;//,cnt=0;
		for(int id=1;id<=k;id++)
			if((s>>(id-1))&1)
			{
				// cnt+=n;
				res+=t[id].x;
				for(int i=1;i<=n;i++)
					e.push_back({n+id,i,t[id].v[i-1]});
			}
		zxscs();
		// while(e.size()&&e.back().x>n)e.pop_back();
		// while(cnt--)e.pop_back();
		e=st;
// cerr<<bitset<2>(s)<<" "<<res<<" "<<ans<<" "<<e.size()<<'\n';
		aans=min(aans,res+ans);
	}
	cout<<aans;
	return 0;
}