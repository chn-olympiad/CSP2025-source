#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+5;
const int M=2e6+5;
int n,m,k;
int fa[N],cn=0,c[N],sum=0;
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	else return fa[x]=find(fa[x]);
}
struct p
{
	int x,y,len;
}a[M];
int cmp(p q,p r)
{
	return q.len<r.len;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n+k+10;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].len;
	}
	if(k==0)
	{
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=a[i].x,y=a[i].y;
			if(find(x)!=find(y))
			{
				fa[find(x)]=find(y);
				cn++;
				sum+=a[i].len;
			}
			if(cn==n-1)
			{
				cout<<sum;
				return 0;
			}
		}
	}
	else
	{
		int cnt=m+1;
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)
			{
				int cost;
				cin>>cost;
				a[cnt].x=n+i;
				a[cnt].y=j;
				a[cnt].len=cost;
				cnt++;
			}
		}
		for(int i=1;i<=k;i++)
		{
			a[cnt].x=n+i;
			a[cnt].y=0;
			a[cnt].len=c[i];
			cnt++;
		}
		cnt--;
//		for(int i=1;i<=cnt;i++)
//		{
//			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].len<<endl; 
//		}
		sort(a+1,a+cnt+1,cmp);
		int now=0;
		for(int i=1;i<=cnt;i++)
		{
			int x=a[i].x,y=a[i].y;
			if(find(x)!=find(y))
			{
				fa[find(x)]=find(y);
				now++;
				sum+=a[i].len;
//				cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].len<<endl;
			}
			if(now==n+k+1-1)
			{
				cout<<sum;
				return 0;
			}
		}
	}
	return 0;
}
/*
4 5 1
1 2 3
2 3 3
3 4 4
4 1 5
2 4 1
0 1 2 3 4

*/
