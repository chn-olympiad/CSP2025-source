#include<bits/stdc++.h>
#define N 10010
#define ll long long
using namespace std;
int n,m,k;
int ff=1;
ll ans;
ll c[N],fa[N],to[N];
struct node
{
	int x,y;
	ll z;
}f;
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int get(int x)
{
	return (x==fa[x])?x:fa[x]=get(fa[x]);
}
vector<node>v;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>f.x>>f.y>>f.z;
		v.push_back(f);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			ff=0;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>to[j];
			if(to[j]!=0)
			{
				ff=0;
			}
		}
	}
	if(ff)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<n;j++)
		{
			for(int kk=j+1;kk<=n;kk++)
			{
				f.x=j;
				f.y=kk;
				f.z=to[j]+to[kk]+c[i];
				v.push_back(f);
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++)
	{
		f=v[i];
		int xx=get(f.x);
		int yy=get(f.y);
		if(xx!=yy)
		{
			fa[xx]=yy;
			ans+=f.z;
		}
	}
	cout<<ans;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
