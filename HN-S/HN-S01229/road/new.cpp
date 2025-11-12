#include<bits/stdc++.h>
#define int long long
#define filein(x) freopen(x".in","r",stdin)
#define fileout(x) freopen(x".out","w",stdout)
using namespace std;
const int N=1e4+13,M=1e6+9;
int fa[N];
int find(int x)
{
	if(fa[x]==x)
	return x;
	return fa[x]=find(fa[x]);
}
struct edge
{
	int l,r,w;
	friend bool operator<(edge i,edge j)
	{
		return i.w<j.w;
	}
}b[M],bb[M],d[13][N];
int top;
int c[13];
int n,m,k;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	filein("road");
	fileout("road");
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].l>>b[i].r>>b[i].w;
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++)
	fa[i]=i;
	int now=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		int l=b[i].l,r=b[i].r;
		if(find(l)==find(r))
		continue;
		fa[find(l)]=find(r);
		now+=b[i].w;
		bb[++top]=b[i];
	}
	ans=now;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j].w;
			d[i][j].l=i+n;
			d[i][j].r=j;
		}
		sort(d[i]+1,d[i]+n+1);
	}
	int S=0;
	int lst=0;
	for(int r=1;r<=k;r++)
	{
		int bst=ans,nd=0;
		for(int p=1;p<=k;p++)
		{
			if((S>>p)&1)
			continue;
			for(int i=1;i<=n+k;i++)
			fa[i]=i;
			int sum=c[p]+lst,l=1,r=1;
			while(l<=top&&r<=n)
			{
				if(l>top)
				{
					int x=d[p][r].l,y=d[p][r].r;
					r++;
					if(find(x)==find(y))
					continue;
					fa[find(x)]=find(y);
					sum+=d[p][r-1].w;
					// cout<<x<<' '<<y<<' '<<<<'\n';
					continue;
				}
				if(r>n)
				{
					int x=bb[l].l,y=bb[l].r;
					l++;
					if(find(x)==find(y))
					continue;
					fa[find(x)]=find(y);
					sum+=bb[l-1].w;
					continue;
				}
				if(bb[l].w<d[p][r].w)
				{
					int x=bb[l].l,y=bb[l].r;
					l++;
					if(find(x)==find(y))
					continue;
					fa[find(x)]=find(y);
					sum+=bb[l-1].w;
					continue;
				}
				else
				{
					int x=d[p][r].l,y=d[p][r].r;
					r++;
					if(find(x)==find(y))
					continue;
					fa[find(x)]=find(y);
					sum+=d[p][r-1].w;
					continue;
				}
			}
			if(sum<bst)
			{
				bst=sum;nd=p;
			}
		}
		if(nd)
		{
			S|=(1<<nd);
			ans=bst;
			lst+=c[nd];
			for(int i=1;i<=top;i++)
			b[i]=bb[i];
			for(int i=1;i<=n;i++)
			b[top+i]=d[nd][i];
			int len=top+n;
			sort(b+1,b+len+1);
			for(int i=1;i<=n+k;i++)
			fa[i]=i;
			top=0;
			// cout<<nd<<':'<<lst<<'\n';
			for(int i=1;i<=len;i++)
			{
				int l=b[i].l,r=b[i].r;
				if(find(l)==find(r))
				continue;
				fa[find(l)]=find(r);
				bb[++top]=b[i];
				// cout<<l<<' '<<r<<' '<<b[i].w<<'\n';
			}
			// cout<<'\n';
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
O(nk^2+nk\log k)
*/