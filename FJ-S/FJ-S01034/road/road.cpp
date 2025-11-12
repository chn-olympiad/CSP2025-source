#include<cstdio>
#include<iostream>
#include<algorithm>
#define M 1000006
#define N 100005
#define int long long
using namespace std;
int n,m,k,f[M],s[12],c[12],bt,ma=100000000000000;
struct aa{
	int u,v,w;
}b[M*10];
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool cm(aa x,aa y){
	return x.w<y.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);bt=m;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&b[i].u,&b[i].v,&b[i].w);
		if(b[i].u>b[i].v)swap(b[i].u,b[i].v);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",c+i);
		for(int j=1,l;j<=n;j++)
		scanf("%lld",&l),
		b[++bt]={j,n+i,l};
	}
	sort(b+1,b+1+bt,cm);
	for(int i=0;i<(1<<k);i++)
	{
		for(int j=1;j<=n+11;j++)f[j]=j;
		int ans=0,id=0;
		s[0]=s[1]=s[2]=s[3]=s[4]=s[5]=s[6]=s[7]=s[8]=s[9]=s[10]=0;
		for(int j=i,k=1;j;j>>=1,k++)
		if(j&1)s[k]=1,id++,ans+=c[k];
		for(int k=1,q=0;k<=bt;k++)
		{
			if((b[k].v<=n||s[b[k].v-n])&&find(b[k].u)!=find(b[k].v))
				f[find(f[b[k].v])]=f[b[k].u],ans+=b[k].w,q++;
			if(q==n+id-1)break;
		}
		ma=min(ma,ans);
	}
	printf("%lld",ma);
}
