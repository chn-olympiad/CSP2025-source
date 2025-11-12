#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int n, m, k;
struct edge
{
	int x, y, w;
}e[2000005], yz[2000005];
struct node
{
	int y, w;
};
vector<node> nbr[N];
int fa[N*4], c[15], a[15][N];
int find(int x)
{
	return fa[x]=((fa[x]==x)?x:find(fa[x]));
}
void unionn(int x, int y)
{
	x=find(x),y=find(y);
	if(x!=y)
	{
		fa[x]=y;
	}
	return ;
}
bool cmp(edge x, edge y)
{
	return x.w<y.w;
}
void work()
{
	for(int i=1;i<=2*n;i++)fa[i]=i;
	sort(e+1,e+1+m,cmp);
	int cnt=0, ans=0;
	for(int i=1;i<=m;i++)
	{
		if(find(e[i].x)!=find(e[i].y))
		{
			unionn(e[i].x,e[i].y);
			ans+=e[i].w;
			cnt++;
			if(cnt==n-1)
			{
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return ;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<fa[i]<<"\n";
//	}
}
bool check()
{
	for(int i=1;i<=k;i++)
	{
		if(c[i])return 0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j])return 0;
		}
	}
	return 1;
}
int num[106], ans=0, kx[2005][25], kxcnt=0;
bool check1()
{
	int lst=find(1);
	for(int i=2;i<=n;i++)
	{
		if(find(i)!=lst)return 0;
	}
	return 1;
}
void dfs(int cur)
{
	if(cur==k+1)
	{
//		bool f=1;
//		for(int i=1;i<=kxcnt;i++)
//		{
//			for(int j=1;j<=k;j++)
//			{
//				if(num[j]==0&&kx[i][j]==1)
//				{
//					f=0;
//				}
//				if(num[j]==1&&kx[i][j]==0)f=1;
//			}
//		}
//		if(!f)return ;
		int now=0;
		for(int i=1;i<=4*n;i++)
		{
			fa[i]=i;
		}
		for(int i=1;i<=m;i++)
		{
			e[i].x=yz[i].x,e[i].y=yz[i].y,e[i].w=yz[i].w;
		}
		int tmp=m, nn=n;
		for(int i=1;i<=k;i++)
		{
			if(num[i]==1)
			{
				nn++;
				now+=c[i];
				for(int j=1;j<=n;j++)
				{
					e[++tmp].x=n+i;
					e[tmp].y=j;
					e[tmp].w=a[i][j];
				}
			}
		}
		sort(e+1,e+1+tmp,cmp);
		int cnt=0;
		for(int i=1;i<=tmp;i++)
		{
			if(find(e[i].x)!=find(e[i].y))
			{
//				cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].w<<"\n";
				unionn(e[i].x,e[i].y);
				now+=e[i].w;
				cnt++;
				if(cnt==nn-1)
				{
					break;
				}
			}
		}
//		cout<<nn<<" "<<now<<"\n";
//		for(int i=1;i<=nn;i++)
//		{
//			cout<<find(i)<<" ";
//		}
//		cout<<"\n";
//		if(!check1())
//		{
//			kxcnt++;
//			for(int i=1;i<=k;i++)
//			{
//				kx[kxcnt][i]=num[i];
//			}
//			return ;
//		}
		ans=min(ans,now);
		return ;
	}
	num[cur]=1;
	dfs(cur+1);
	num[cur]=0;
	dfs(cur+1);
	return ;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x, y, w;
		cin>>x>>y>>w;
		e[i].x=x,e[i].y=y,e[i].w=w;
		yz[i].x=x,yz[i].y=y,yz[i].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if(!k)
	{
		work();
		return 0;
	}
	if(check())
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=4*n;i++)fa[i]=i;
	sort(e+1,e+1+m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(find(e[i].x)!=find(e[i].y))
		{
//			cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].w<<"\n";
			unionn(e[i].x,e[i].y);
			ans+=e[i].w;
			cnt++;
			if(cnt==n-1)
			{
				break;
			}
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
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
