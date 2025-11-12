#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct oo{
	int u,v;
	long long w;
	int id;
	bool operator < (const oo &a) const{
		return w<a.w;
	}
};
long long a[11][10010],c[11];
int fa[20010];
oo t[4000010];
int top=0;
inline int find(int x)
{
	while(fa[x]!=x)
	{
		fa[x]=fa[fa[x]];
		x=fa[x];
	}
	return x;
}
int v[200010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		int u,v;
		long long w;
		cin>>u>>v>>w;
		t[++top]={u,v,w,0};
	}
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		for(j=1;j<=n;j++) cin>>a[i][j],t[++top]={i+n,j,a[i][j],i};
	}
	t[++top]={0,0,0,0};
	sort(t+1,t+top+1);
	long long da=1e18;
	long long yc;
	for(i=0;i<pow(2,k);i++)
	{
		int bj=0;
		for(j=1;j<i;j++)
		{
			if(v[j]&&((i&j)==j)) { bj=1; break; }
		}
		if(bj==1) continue;
		long long js=0;
		for(j=0;j<11;j++) if(1&(i>>j)) js+=c[j+1];
		for(j=1;j<=n+k;j++) fa[j]=j;
 		for(j=1;j<=top;j++)
		{
			oo nw=t[j];
			if(nw.id!=0&&!(1&(i>>(nw.id-1)))) continue;
			int u=find(nw.u),v=find(nw.v);
			if(u==v) continue;
			js+=nw.w;
			fa[u]=v;
		}
		if(i==0) yc=js;
		else if(js<yc) v[i]=0;
		else v[i]=1;
		da=min(da,js);
	}
	cout<<da;
	return 0;
}
