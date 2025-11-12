#include<bits/stdc++.h>
using namespace std;
#define int long long
int in()
{
	int k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
void out(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
}
const int N=1.5e4;
struct dsu
{
	int f[N],h[N];
	void init(int n){for(int i=1;i<=n;i++)f[i]=i,h[i]=1;}
	int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
	void merge(int x,int y)
	{
		if((x=find(x))==(y=find(y)))return;
		if(h[x]>h[y])swap(x,y);
		f[x]=y,h[y]+=(h[x]==h[y]);
	}
}f;
struct edge
{
	int u,v,w;
	bool operator<(const edge &a)const{return w<a.w;}
};vector<edge>e,kk;
int n,m,k;
int kruskal(int type,vector<edge>&e)
{
	int ans=0;f.init(n+k);
	sort(e.begin(),e.end());
	for(edge g:e)
	{
		int u=g.u,v=g.v,w=g.w;
		if(f.find(u)==f.find(v))continue;
		f.merge(u,v),ans+=g.w;
		if(type)kk.push_back((edge){u,v,w});
	}
	return ans;
}
int a[20][N],c[20];
signed main()
{
//	system("fc road4.ans road.out");return 0;
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	n=in(),m=in(),k=in();
	while(m--)
	{
		int u=in(),v=in(),w=in();
		e.push_back((edge){u,v,w});
	}
	int ans=kruskal(1,e);
	for(int i=1;i<=k;i++)
	{
		c[i]=in();
		for(int j=1;j<=n;j++)a[i][j]=in();
	}
	for(int S=1;S<(1<<k);S++)
	{
		vector<edge>p=kk;
		int sum=0;
		for(int i=1;i<=k;i++)
			if((S>>(i-1))&1)
			{
				sum+=c[i];
				for(int j=1;j<=n;j++)p.push_back((edge){n+i,j,a[i][j]});
			}
		ans=min(ans,sum+kruskal(0,p));
	}
	out(ans);
	return 0;
}
