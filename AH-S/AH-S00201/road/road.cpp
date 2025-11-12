#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,v;
	node(int xx,int vv){x=xx,v=vv;}
};
vector<node> e[10005];
int v[10005];
bool f[10005];
inline void dfs(int x)
{
	for(auto it:e[x])
	{
		if(!f[it.x]&&v[it.x]>it.v)
		{
			v[it.x]=it.v;
			f[it.x]=1;
			dfs(it.x);
			f[it.x]=0;
		}
	}
	return ;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(v,0x3f,sizeof v);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		e[x].push_back(node{y,w});
		e[y].push_back(node{x,w});
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		int y[10005];
		//~ memset(y,0,sizeof y);
		for(int j=1;j<=n;j++)
		{
			cin>>y[j];
			//~ e[n+i].push_back(node{j,x+y});
			//~ e[j].push_back(node{n+i,x+y});
			//~ e[n+i].push_back(node{j,x+y});
			//~ e[j].push_back(node{n+i,x+y});
			//~ for(int l=1;l<j;l++)
			//~ {
				//~ e[j].push_back(node{l,y[j]+y[l]+x});
				//~ e[l].push_back(node{j,y[j]+y[l]+x});
				//~ cout<<i<<" "<<j<<" "<<l<<" "<<y[j]<<" "<<y[l]<<" "<<x<<"\n";
			//~ }
		}
		for(int j=2;j<=n;j++)
		{
			for(int l=1;l<j;l++)
			{
				e[j].push_back(node{l,y[j]+y[l]+x});
				e[l].push_back(node{j,y[j]+y[l]+x});
				 //~ cout<<i<<" "<<j<<" "<<l<<" "<<y[j]<<" "<<y[l]<<" "<<x<<"\n";

			}
		}
	}
	//~ for(int i=1;i<=n;i++)
	//~ {
		//~ for(auto it:e[i])  cout<<i<<""<<""<<it.x<<" "<<it.v<<"   ";
		//~ cout<<"\n";
	//~ }
	//~ for(int )
	//~ n+=k;
	v[1]=0;
	for(int i=1;i<=n;i++)  dfs(i);
	int ans=0;
	for(int i=1;i<=n;i++)  ans+=v[i];
	cout<<ans;
	return 0;
}
