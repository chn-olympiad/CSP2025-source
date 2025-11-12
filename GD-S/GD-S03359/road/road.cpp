#include<bits/stdc++.h>

using namespace std;

struct edge
{
	int u,v;
	int w;
};
vector<edge> e;

bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int n,m,k,nn;
int fa[10005];
int c;
int ck[10005];
int flg[10005];
int ansx;
void merge(int a,int b)
{
	while(fa[a]!=a)
	{
		int t=a;
		a=fa[a];
		fa[t]=b;
	}
	fa[a]=fa[b];
}
bool find(int a,int b)
{
	while(fa[a]!=a)
	{
		a=fa[a];
	}
	while(fa[b]!=b)
	{
		b=fa[b];
	}
	return (a==b);
}

vector<edge> ans;

void mst()
{
	for(int i=1;i<=n;i++)
	{
//		cout<<"points:"<<e[i].u<<" "<<e[i].v<<'\n';
//		cout<<"fathers:"<<fa[e[i].u]<<" "<<fa[e[i].v]<<endl;
		if(!find(e[i].u,e[i].v))
		{
			ans.push_back(e[i]);
			merge(e[i].u,e[i].v);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int tu,tv,tw;
	for(int i=1;i<=m;i++)
	{
		cin>>tu>>tv>>tw;
		e.push_back({tv,tu,tw});
		e.push_back({tu,tv,tw});
	}
	
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>ck[j];
			flg[j]=1;
		}
		for(int j=1;j<=n;j++)
		{
			for(int kk=1;kk<=n;kk++)
			{
				if(j==kk)
				{
					continue;
				}
				e.push_back({j,kk,ck[j]+ck[kk]+c});
				e.push_back({kk,j,ck[j]+ck[kk]+c});
			}
		} 
	}
	sort(e.begin(),e.end(),cmp);
	mst();
	

	for(int i=0;i<ans.size();i++)
	{
		ansx+=ans[i].w;
		//cout<<ans[i].u<<" "<<ans[i].v<<" "<<ans[i].w<<'\n';
	}
	cout<<ansx;
	return 0;
	
}
