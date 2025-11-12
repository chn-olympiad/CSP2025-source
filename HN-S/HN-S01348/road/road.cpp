#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+100,maxm=1e6+5;
int cnt=0,f[maxn],siz[maxn],tag[11],n,m,k,c[11],u[maxm],v[maxm],w[maxm],uu[maxm],vv[maxm],ww[maxm],id[maxm],edge[maxm],edge1[maxm];
bool cmp(int x,int y)
{
	return w[x]<w[y];
}
int find(int x)
{
	if(x!=f[x])
	{
		f[x]=find(f[x]);
	}
	return f[x];
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		if(siz[x]<siz[y])
		{
			swap(x,y);
		}
		f[y]=x;
		siz[x]+=siz[y];
	}
}
bool cmp1(int x,int y)
{
	return ww[x]<ww[y];
}
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
int main()
{
//	int t=read();
//	cout<<t<<"\n";
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		u[i]=read();
		v[i]=read();
		w[i]=read();
		edge[i]=i;
	}
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n+k;i++)
		f[i]=i,siz[i]=1;
	ll ans=0,maxi=0;
	for(int i=1;i<=m;i++)
	{
		if(find(u[edge[i]])!=find(v[edge[i]]))
		{
			merge(u[edge[i]],v[edge[i]]);
			uu[++cnt]=u[edge[i]];
			vv[cnt]=v[edge[i]];
			ww[cnt]=w[edge[i]];
			id[cnt]=0;
			maxi+=w[edge[i]];
			edge1[cnt]=cnt;
		}
	}
	ans=maxi;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			int w=read();
			uu[++cnt]=n+i;
			vv[cnt]=j;
			ww[cnt]=w;
			id[cnt]=i;
			edge1[cnt]=cnt;
		}
	}
	sort(edge1+1,edge1+cnt+1,cmp1);
	for(int i=0;i<(1<<k);i++)
	{
		memset(tag,0,sizeof(tag));
		ll maxi=0;
		int tot1=0;
		for(int j=0;j<k;j++)
		{
			if(i&(1<<j))
			{
				maxi+=c[j+1];
				tag[j+1]=1;
				tot1++;
			}
		}
		for(int j=1;j<=n+k;j++)
			f[j]=j,siz[j]=1;
		tag[0]=1;
		int tot=0;
		for(int j=1;j<=cnt;j++)
		{
			if(tag[id[edge1[j]]]&&(find(uu[edge1[j]])!=find(vv[edge1[j]])))
			{
				merge(find(uu[edge1[j]]),find(vv[edge1[j]]));
				maxi+=ww[edge1[j]];
				tot++;
				if(tot==tot1+n-1)
					break;
			}
		}
		if(tot==tot1+n-1)
		ans=min(ans,maxi);
	}
	cout<<ans;
}
