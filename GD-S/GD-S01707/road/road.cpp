#include <bits/stdc++.h>
using namespace std;
struct edge
{
	int u,v,w;
};
vector<edge> e(1000002); 
struct city
{
	int v,w;
};
vector<city> g[10001];
int town[11][10001];
int f[10010];
int find(int p)
{
	if(f[p]==p) return p;
	return f[p]=find(f[p]);
}
bool cmp(edge a,edge b)
{
	return a.w<b.w; 
}
int krustal(int n,int m)
{
	set<int> s;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e.begin()+1,e.end()+1,cmp);
	int cnt=1,sum=0;
	int i=1;
	while(cnt<n)
	{
		if(find(e[i].u)!=find(e[i].v))
		{	
			
			/*cout<<e[i].u<<' '<<e[i].v<<endl;
			cout<<find(e[i].u)<<' '<<find(e[i].v)<<endl;*/
			if(s.count(e[i].u)) f[e[i].v]=find(f[e[i].u]);
			else f[e[i].u]=find(f[e[i].v]);
			s.insert(e[i].u);
			s.insert(e[i].v);
			cnt++;//cout<<cnt<<' '<<n<<endl;
			sum+=e[i].w;
		}
		i++;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	bool flag=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
		//g[u].push_back({v,w});
		//g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++) 
		{
			cin>>town[i][j];
			if(town[i][j]!=0) flag=1;
		}
	if(k>0 && !flag)
	{
		cout<<0;
		return 0;
	}
	else if(k==0)
	{
		cout<<krustal(n,m);
		return 0;
	}
	else 
	{
		vector<edge> e1=e;
		int minn=krustal(n,m);
		//cout<<minn<<endl;
		for(int l=1;l<=k;l++)
		{
			for(int r=l;r<=k;r++)
			{
				int newn=n+r-l+1;
				int tmp=n,nsum=0;
				for(int t=l;t<=r;t++)
				{
					nsum+=town[t][0];
					for(int i=1;i<=n;i++)
					{
						e.push_back({tmp+t-l+1,i,town[t][i]});
						//cout<<"!!!!"<<endl;
						//cout<<e[e.size()-1].u<<' '<<e[e.size()-1].v<<' '<<e[e.size()-1].w<<endl;
					}
				}
				//cout<<krustal(newn,m+n)<<endl;
				nsum+=krustal(newn,m+n);
				if(nsum<minn) //cout<<l<<' '<<r<<endl;
				minn=min(nsum,minn);
				e=e1;
			}
		}
		cout<<minn;
	}	
	return 0;
}
