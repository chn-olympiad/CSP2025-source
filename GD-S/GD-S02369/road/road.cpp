#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cc,x,y,w,c[100001],a[16][100006],ans=1e15,fa[100001];
struct id{
	int fr,to,w;
	bool operator <(const id &d)const{
		return w<d.w;
	}
}e[2000001];
int zbb(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=zbb(fa[x]); 
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) 
	{
		cin>>e[i].fr>>e[i].to>>e[i].w;
	}
	cc=m;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(m>100000)
	{
		cout<<0;
		return 0;
	}
	int st=(1<<k);
	for(int i=0;i<st;i++)
	{
		cc=m;
		int tmp=0;
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=k;j++)
		{
			if(i>>(j-1)&1)
			{
				tmp+=c[j];
				for(int l=1;l<=n;l++)
				{
					e[++cc].fr=j+n;
					e[cc].to=l;
					e[cc].w=a[j][l];
				}
			}
		}
//		cout<<"EnD\n";
		sort(e+1,e+1+cc);
		for(int j=1;j<=cc;j++)
		{
			int ux=zbb(e[j].fr),uy=zbb(e[j].to);
			if(ux!=uy)
			{
				fa[uy]=ux;
				tmp+=e[j].w;
			 } 
		}
		ans=min(ans,tmp);
//		cout<<tmp<<endl;
	}
	cout<<ans;
}
