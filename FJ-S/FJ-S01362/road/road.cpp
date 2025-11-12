#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long u,v,w;
};
node s[1001005];
long long edge[1005][1005],N,M,K,F;
long long fa[1005],c,a[1005];
long long Ans;
int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
void join(int x,int y)
{
	int f1=find(x),f2=find(y);
	if(f1!=f2)
		fa[f1]=f2;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(edge,0x7f,sizeof(edge));
	scanf("%lld %lld %lld",&N,&M,&K);
	for(int i=1;i<=N;i++)
		fa[i]=i;
	for(int i=1;i<=M;i++)
	{
		long long u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		if(u>v)
			swap(u,v); 
		if(K!=0)
			edge[u][v]=min(edge[u][v],w);
		else
			s[i]={u,v,w};
	}
	if(K==0)
		F=M;
	for(int i=1;i<=K;i++)
	{
		scanf("%lld",&c);
		for(int j=1;j<=N;j++)
			scanf("%lld",&a[j]);
		for(int j=1;j<=N;j++)
		{
			for(int k=j+1;k<=N;k++)
				edge[j][k]=min(edge[j][k],a[j]+a[k]+c);
		}
	}
	if(K!=0)
	{
		for(int i=1;i<=N;i++)
			for(int j=i+1;j<=N;j++)
				if(edge[i][j]<=0x7f7f7f7f)
					 s[++F]={i,j,edge[i][j]};
	}
	sort(s+1,s+1+F,cmp);
	int it=1;
	for(int i=1;i<N;i++)
	{
		while(find(s[it].u)==find(s[it].v))
			it++;
		join(s[it].u,s[it].v),Ans+=s[it].w,it++;
	}
	printf("%lld",Ans);
	return 0;
}
