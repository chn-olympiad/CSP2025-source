#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,w;
};
vector<node> E;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int f[1000005];
int fr(int x)
{
	if (f[x]==x) return x;
	else return f[x]=fr(f[x]);
}
void un(int x,int y)
{
	f[fr(x)]=f[fr(y)];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if (k==0)
	{
		for (int i=1;i<=m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			E.push_back({u,v,w});
		}
		for (int i=1;i<=n;i++) f[i]=i;
		sort(E.begin(),E.end(),cmp);
		int sum=0,r=1;
		for (auto x:E)
		{
			int u=x.u;
			int v=x.v;
			int w=x.w;
			if (fr(u)!=fr(v))
			{
				sum+=w;
				r++;
				un(u,v);
			}
			if (r==n) break;
		}
		cout<<sum;
	}
	return 0;
}
