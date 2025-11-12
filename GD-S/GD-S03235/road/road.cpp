#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
ll n,m,k,cj[15],dis[N],ans;

struct node{
	int ti,wi;//ti 另一个点 wi 边权 
};
vector<node> e[N]; 
ll cc[15][N];
bool v[N],f[15];
queue<int> q;
void kruskal()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	//q.push(1);
	//v[1]=true;
//	while(!q.empty())
//	{
//		int h=q.front();
//		q.pop();
//		
//	}
	for(int i=1;i<n;i++)
	{
		int p=0;
		for(int j=1;j<=n;j++)
			if(!v[j]&&(p==0||dis[j]<dis[p]))//找于生成树最近点
				p=j;
		v[p]=true;
		for(int j=0;j<e[p].size();j++)
		{
			node k=e[p][j];
			int t=k.ti,w=k.wi;
			if(v[t]) continue;//已在生成树里面 
			if(dis[t]>w)
			dis[t]=w;
		 } 
		 //改进 在每次加入生成树时判断 
//		 for(int cs=1;cs<=k;cs++)
//		 if(cj[cs]+cc[cs][i]+cc[cs][j]<max(dis[i],dis[j]))
	}
	for(int i=1;i<=n;i++)
		ans+=dis[i];
//	for(int id=1;id<=k;id++)
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++)
//				if(cj[id]+cc[id][i]+cc[id][j]<max(dis[i],dis[j]))
//				{
//						ans-=max(dis[i],dis[j]);
//						ans+=cj[id]+cc[id][i]+cc[id][j];
//				}
				
					
}
int main()
{
	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1,t;i<=k;i++)
	{
		cin>>cj[i];
	//	ans+=cj[i];
		for(int j=1;j<=n;j++)
		cin>>cc[i][j];
		
	}
	kruskal();
	cout<<ans;
	return 0;
}
//Ren5Jie4Di4Ling5%
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
