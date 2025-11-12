#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e6+5,MAXD=1e4+5;
int n,m,k,x,y,a[MAXD],fa[MAXD],ans;
int s,k1[MAXN];
ll z;
priority_queue<int,vector<int>,less<int> > q1;
struct node{
	int x,v;
	ll w;
	operator <(const node &a)const{
		return w<a.w;
	}
};
vector<int> ed[MAXN],edw[MAXN];
map<int,int> ma[MAXD];
void add(int x,int y,ll z)
{
	ed[x].push_back(y);
	edw[x].push_back(z);
}
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void kruskal()
{
	priority_queue<node,vector<node>,less<node> > q;
	q.push({0,1,0});
	while(!q.empty())
	{
		int u=q.top().v,w=q.top().w;
		q.pop();ans+=w;
		for(int i=0;i<ed[u].size();i++)
		{
//			cout<<11111111111111;
			int v=ed[u][i];
			int fu=find(u),fv=find(v);
//			cout<<"         "<<fu<<endl;
			if(fu==fv)
				continue;
			if(fu<fv) fa[fv]=fu;
			else fa[fu]=fv;
			q1.push(edw[u][i]);
			s++;
			k1[s]=edw[u][i];
			q.push({u,v,edw[u][i]});
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	kruskal();
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&x);
		int s=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			for(int k=1;k<j;k++)
			{
//				if(ma[j][k]>0)
//					cout<<j<<" "<<k<<' '<<ma[j][k]<<endl;
				if(q1.top()>a[j]+a[k])
				{
					s+=q1.top()-(a[j]+a[k]);
					q1.pop();
					q1.push(a[j]+a[k]);
				}
			}
		}
		if(x-s<0)
			ans+=x-s;
		while(!q1.empty())
			q1.pop();
		for(int j=1;j<=s;j++)
			q1.push(k1[j]);
	}
	printf("%d",ans);
	return 0;
}
