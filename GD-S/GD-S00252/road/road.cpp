//t2 (rp<<=rp)<<=rp
#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;

const int N=1e4+100;
int n,m,k,c[N],minn[N];
bool vis[N],flag[20];
vector<PII>vc[N];

inline ll Prim(int st,int suc)
{
	ll res=0,dot=0;
	priority_queue<PII,vector<PII>,greater<PII>>q;
	memset(vis,0,sizeof(vis));
	memset(minn,0x3f,sizeof(minn));
	q.push({0,st});
	while(!q.empty())
	{
		auto tp=q.top();
		q.pop();
		int v=tp.first,u=tp.second;
		if(vis[u])continue;
		res+=v,vis[u]=1,dot++;
//		cout<<u<<"±»ËÉ³Ú\n";		
		if(dot==suc)return res;
		for(auto x:vc[u])
		{
			int to=x.first,w=x.second;
//			cout<<u<<"->"<<to<<endl; 
			if(!vis[to] && minn[to]>w)
			{
				minn[to]=w;
				if(to<=n)q.push({w,to});
				else if(to<=n+k && flag[to-n])q.push({w,to});
			}
		}
	}
	return res;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		vc[u].push_back({v,w});
		vc[v].push_back({u,w});
	}
	bool xingzhiA=1;
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		if(c[i])xingzhiA=0;
		for(int j=1;j<=n;++j)
		{
			int val;cin>>val;
			vc[n+i].push_back({j,val});
			vc[j].push_back({n+i,val});
		}
	}
	ll ans=9e18;
	if(xingzhiA && m>5e5 && k>5)
	{
		ans=0;
		int i=(1ll<<k)-1;
		for(int j=0;j<k;++j)
		{
			int l=(i>>j)&1;
			if(l&1)flag[j+1]=1,ans+=c[j+1];
		}
		cout<<ans+Prim(1,n+k);
		return 0;
	}
	for(int i=0;i<(1<<k);++i)
	{
		memset(flag,0,sizeof(flag));
		ll sum=0,cnt=0;
		for(int j=0;j<k;++j)
		{
			int l=(i>>j)&1;
			if(l&1)cnt++,flag[j+1]=1,sum+=c[j+1];
		}
		if(sum>ans)continue;
		sum+=Prim(1,n+cnt);
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
