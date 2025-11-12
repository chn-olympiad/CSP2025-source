#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[10050],ans,cnt,o,cc,l[10050],p[1050][1050];
struct node
{
	long long u,v,w; 
}g[2000050];
long long find(long long x)
{
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
bool cmp(node i,node j)
{
	return i.w<j.w;
}
long long read()
{
	long long p=0;
	char x=getchar();
	while(x>='0'&&x<='9')
	{
		p=p*10+x-'0';
		x=getchar();
	}
	return p;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(p,0x3f3f3f3f,sizeof(p));
	n=read();
	m=read();
	k=read();
	for(long long i=1;i<=n;i++)f[i]=i;
	for(long long i=1;i<=m;i++)
	{
		long long u,v,w;
		u=read();
		v=read();
		w=read();
		g[i].u=u;
		g[i].v=v;
		g[i].w=w;
		p[u][v]=min(p[u][v],w);
		p[v][u]=min(p[v][u],w);
	}
	if(k==0)
	{
		sort(g+1,g+1+m,cmp);
		for(long long i=1;i<=m;i++)
		{
			long long a=g[i].u,b=g[i].v,c=g[i].w;
			long long fa=find(a),fb=find(b);
			if(fa!=fb)
			{
				f[fa]=fb;
				ans+=c;
				cc++;
			}
			if(cc>=n)break;
		}
	}
	else
	{
		long long cnt=m;
		for(long long i=1;i<=k;i++)
		{
			o=read();
			for(long long j=1;j<=n;j++)
			{
				l[j]=read();
			}
			for(long long i=1;i<=n;i++)
			{
				for(long long j=i;j<=n;j++)
				{
						if(p[i][j]>l[i]+l[j]||p[j][i]>l[i]+l[j])
						{
							g[++cnt].u=i;
							g[cnt].v=j;
							g[cnt].w=l[i]+l[j];
							p[i][j]=l[i]+l[j];
							p[j][i]=l[i]+l[j];
						}
					
				}
			}
		}
		sort(g+1,g+1+cnt,cmp);
		for(long long i=1;i<=cnt;i++)
		{
			long long a=g[i].u,b=g[i].v,c=g[i].w;
			long long fa=find(a),fb=find(b);
			if(fa!=fb)
			{
				f[fa]=fb;
				ans+=c;
				cc++;
			//	cout<<a<<" "<<b<<" "<<endl;
			}
			if(cc>=n)break;
		}
	}
	cout<<ans;
 } 
