#include <iostream>
#include <algorithm>
using namespace std;
struct bian{
	int u,v,w,sp;
	friend bool operator<(bian x,bian y)
	{
		return x.w<y.w;
	}
} bn[1100032];
int _sv1[12];
//struct node{
//	int v,w;
//};
//vector<node> a[10002];
int n,m,k,u,v,w;
int fa[10032];
int town[12];
int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y)
{
	if (x==y) return 0;
	int nx=find(x),ny=find(y);
	if (nx!=ny)
	{
		fa[nx]=ny;
		return 1;
	}
	return 0;
}
long long solve1()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	int sbn=m+n*k;
	for (int i=m+1;i<=sbn;i++)
	{
		for (int j=1;j<=k;j++)
		{
			if (bn[i].u==n+j)
			{
				bn[i].u=_sv1[j];//not unique
			}
		}
	}/*
	for (int i=1;i<=m+n*k;i++)
	{
		cout<<bn[i].u<<' '<<bn[i].v<<' '<<bn[i].w<<' '<<bn[i].sp<<endl;
	}*/
	sort(bn+1,bn+sbn+1);
	int num=0;
	long long sum=0;
	for (int i=1;i<=sbn;i++)
	{
		if (merge(bn[i].u,bn[i].v))
		{
			sum+=bn[i].w;
			num++;
			if (num==n-1)
			{
				return sum;
			}
		}
	}
	
}
long long zxscs(int x)
{
	// already sort
/*	for (int i=1;i<=m+n*k;i++)
	{
		cout<<bn[i].u<<' '<<bn[i].v<<' '<<bn[i].w<<' '<<bn[i].sp<<endl;
	}*/
	int _n=n;
	long long sum=0;
	for (int i=0;i<k;i++)
	{
		if ((1<<i)&x)
		{
			_n++;
			sum+=town[i+1];
		} 
	}
//	cout<<"now_n:"<<_n;
	for (int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	int num=0;
	int sbn=n+m*k;
	for (int i=1;i<=sbn;i++)
	{
		if (bn[i].sp==0 || ((1<<(bn[i].sp-1))&x))
			if (merge(bn[i].u,bn[i].v))
			{
				sum+=bn[i].w;
//				cout<<"sum->"<<((1<<(bn[i].sp-1))&x)<<' '<<sum<<' ';
				num++;
				if (num==_n-1)
				{
//	cout<<"nowsum:"<<sum<<endl;
					return sum;
				}
			}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		bn[i]=bian{u,v,w,0};
//		a[v].push_back(node{u,w});
//		a[u].push_back(node{v,w});
	}
	int sv1=1;
//	sv1=0;
	int cnt=m;
	for (int i=1;i<=k;i++)
	{
		cin>>u;
		town[i]=u;
		if (u!=0) sv1=0;
		for (int j=1;j<=n;j++)
		{
			cin>>w;
			if (w==0) _sv1[i]=j;
			bn[++cnt]=bian{i+n,j,w,i};
		}
		if (!_sv1)sv1=0;
	}
	if (sv1) {
		cout<<solve1();
		return 0;
	}
	int bsum=1<<k;
	int sbn=n+m*k;
	sort(bn+1,bn+sbn+1);
	long long sum=1e18;
	for (int i=0;i<bsum;i++)
	{
		
		sum=min(sum,zxscs(i)); //zui xiao sheng cheng shu
	}
	cout<<sum;
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