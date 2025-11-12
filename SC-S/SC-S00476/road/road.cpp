#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define sinzo return
#define code 0
#define pii pair<int,int> 
#define ex exit(0)
using namespace std;
const int N=2e6+10;
const int mod=1e9+7;
int b[N],c[11][N];
int n,m,k,l,cnt,sum,ans,tsf=1;

struct edge
{
	int to,next,l;
}e[N];
struct min_tree_edge
{
	int l,r,s;
}mte[N];
bool mtcmp(min_tree_edge a,min_tree_edge b)
{
	return a.s<b.s;
}
int h[N];
void add(int u,int v,int l)
{
	e[++cnt]={v,h[u],l};
	h[u]=cnt;
}
int fa[N];
int bcfind(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=bcfind(fa[x]); 
}
int zxshchshu()
{
	for(int rp=1;rp<=m;rp++)
	{
		if(bcfind(mte[rp].l)!=bcfind(mte[rp].r))
		{
			fa[bcfind(mte[rp].l)]=bcfind(mte[rp].r);
			ans+=mte[rp].s;
			sum--;
		}
	}
	return ans;
}
int zxshchshu2()
{
	for(int rp=1;rp<=cnt;rp++)
	{
		if(bcfind(mte[rp].l)!=bcfind(mte[rp].r))
		{
			fa[bcfind(mte[rp].l)]=bcfind(mte[rp].r);
			ans+=mte[rp].s;
			sum--;
		}
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n<0||m<0||k<0)
	{
		while(1)
		{
			cout<<"sinzo rp++\n";
		}
		ex;
	}
	sum=n;
	if(k==0)
	{
		for(int rp=1;rp<=m;rp++)
		{
			int u,v,l;
			cin>>u>>v>>l;
			mte[rp]={u,v,l};
			fa[rp]=rp;
		}
		sort(mte+1,mte+1+m,mtcmp);
		cout<<zxshchshu();
		ex;
	}
	for(int rp=1;rp<=m;rp++)
	{
		int u,v,l;
		cin>>u>>v>>l;
		add(u,v,l);
		add(v,u,l);
		mte[rp]={u,v,l};
		fa[rp]=rp;
	}
	sort(mte+1,mte+1+m,mtcmp);
	for(int rp=1;rp<=k;rp++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>c[rp][j];
		}
		if(c[rp][0]!=0)tsf=0;
	}
	if(tsf)
	{
		if(n>1000)
		{
			cout<<zxshchshu();
			ex;
		}
		cnt=m;
		for(int rp=1;rp<=n;rp++)
		{
			for(int j=rp+1;j<=n;j++)
			{
				mte[++cnt]={rp,j,c[rp][j]};
			}
		}
		sort(mte+1,mte+1+cnt,mtcmp);
		cout<<zxshchshu2();
		ex;
	}
	
	cout<<zxshchshu();
	sinzo code;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
/* 
40.

请输入文本
luogu sinzo 873466

*/