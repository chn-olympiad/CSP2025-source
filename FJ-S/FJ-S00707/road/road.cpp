#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+15;
const ll M=1e4+15; 
struct Node{
	ll u,v,w;
}a[N];
bool cmp(Node a,Node b)
{
	return a.w<b.w;
}
ll n,m,c[11],k,ans,d[11][M],f[M],vv[N];
ll find(ll a)
{
	if(f[a]!=a)
	{
		f[a]=find(f[a]);
	}
	return f[a];
}
void kruskar()
{
	ll sum=0,cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(cnt==n)
		{
			break;
		}
//		ll p=0;
//		for(int j=2;j<=n;j++)
//		{
//			if(f[j]!=f[1])
//			{
//				p=1;
//				break;
//			}
//		}
//		if(p==0)
//		{
//			break;
//		}
		ll u1=a[i].u,v1=a[i].v;
		ll fu=find(u1);
		ll fv=find(v1);
//		cout<<u1<<' '<<v1<<" "<<fu<<" "<<fv<<endl;
		if(fv==fu)
		{
			continue;
		}
		if(u1>=1&&u1<=n&&vv[u1]==0)
		{
			cnt++;
			vv[u1]=1;
		}
		if(v1>=1&&v1<=n&&vv[v1]==0)
		{
			cnt++;
			vv[v1]=1;
		}
		sum+=a[i].w;
		f[fu]=fv;
//		cout<<a[i].u<<" "<<a[i].v<<endl;
	}
	cout<<sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll res=m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j];
			a[++res].u=n+i;
			a[res].v=j;
			a[res].w=d[i][j];
		}
	}
//	if(k==0)
//	{
		for(int i=1;i<=n+k;i++)
		{
			f[i]=i;
		}
		sort(a+1,a+m+1,cmp);
		kruskar();
		return 0;
//	}
	
	return 0;
}
/*
6 8 0
1 2 3
1 4 5
1 5 4
2 6 1
2 3 4
3 4 6
4 5 2
5 6 1
1 8
1 2
2 3
1 4
13
*/
