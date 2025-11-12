#include<bits/stdc++.h>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _antirep(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define fir first
#define sec second 
using namespace std;
typedef long long LL;

const int N=1e5+5;

int n,cnt[5];
bool done[N];

struct node
{
	int a,b,c;
}e[N];

vector<pii>id[5];

bool cmp(pii A,pii B)
{
	return A.fir>B.fir;
}

void solve()
{
	int ans=0;
	
	cin>>n;
	
	_rep(o,1,3) id[o].clear();
	_rep(i,1,n) done[i]=0;
	
	_rep(i,1,n)
	{
		cin>>e[i].a>>e[i].b>>e[i].c;
		
		int tmp=max(max(e[i].a,e[i].b),e[i].c);
		
		if(e[i].a==tmp)
		{
			int rmax=max(e[i].b,e[i].c);
			id[1].push_back({tmp-rmax,i});
		}
		else if(e[i].b==tmp)
		{
			int rmax=max(e[i].a,e[i].c);
			id[2].push_back({tmp-rmax,i});
		}
		else if(e[i].c==tmp)
		{
			int rmax=max(e[i].a,e[i].b);
			id[3].push_back({tmp-rmax,i});
		}
	}
	
	_rep(o,1,3) sort(id[o].begin(),id[o].end(),cmp),cnt[o]=0;
	
	_rep(o,1,3)
	{
		for(pii sd:id[o])
		{
			int x=sd.sec;
			if(done[x]) continue;
			if(cnt[o]>=n/2) break;
			cnt[o]++;
			done[x]=1;
			if(o==1) ans+=e[x].a;
			if(o==2) ans+=e[x].b;
			if(o==3) ans+=e[x].c;
		}
	}
	
	_rep(o,1,3) id[o].clear();
	
	_rep(i,1,n)
	{
		if(!done[i])
		{
			int tmp=max(max(e[i].a,e[i].b),e[i].c);
			
			if(e[i].a==tmp)
			{
				if(e[i].b>e[i].c) id[2].push_back({e[i].b-e[i].c,i});
				else id[3].push_back({e[i].c-e[i].b,i});
			}
			else if(e[i].b==tmp)
			{
				if(e[i].a>e[i].c) id[1].push_back({e[i].a-e[i].c,i});
				else id[3].push_back({e[i].c-e[i].a,i});
			}
			else if(e[i].c==tmp)
			{
				if(e[i].a>e[i].b) id[1].push_back({e[i].a-e[i].b,i});
				else id[2].push_back({e[i].b-e[i].a,i});
			}
		}
	}
	
	_rep(o,1,3)
	{
		for(pii sd:id[o])
		{
			int x=sd.sec;
			if(done[x]) continue;
			if(cnt[o]>=n/2) break;
			cnt[o]++;
			done[x]=1;
			if(o==1) ans+=e[x].a;
			if(o==2) ans+=e[x].b;
			if(o==3) ans+=e[x].c;
		}
	}
	
	_rep(i,1,n)
		if(!done[i])
			ans+=min(min(e[i].a,e[i].b),e[i].c);
			
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	
	int T;cin>>T;
	while(T--) solve();
	return 0;
 } 
