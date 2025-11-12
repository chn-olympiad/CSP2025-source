#include<bits/stdc++.h>
using namespace std;
long long h[1000000],fa[10000000];
struct lyc {
	long long u,v,w,next;
}q[10000000];
long long cnt;
void add(long long u,long long v,long long w)
{
	cnt++;
	q[cnt].next=h[u];
	q[cnt].u=u;
	q[cnt].v=v;
	q[cnt].w=w;
	h[u]=cnt;
 } 
 bool cmp(lyc x,lyc y)
 {
 	return x.w<y.w;
 }
 int find(int x)
 {
 	if(fa[x]==x)
 	return x;
 	 fa[x]=find(fa[x]);
	  return fa[x];
 }
 void join(int a,int b)
 {
 	long long f1,f2;
 	f1=find(a);
 	f2=find(b);
 	if(f1!=f2)
 	{
 		fa[f1]=f2;
	 }
 }
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	for(long long i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{long long a;
		cin>>a;
		for(int j=1;j<=n;j++)
		{long long t;
		cin>>t;
			
			add(n+i,j,t);
		}
	}
	sort(q+1,q+1+m+k*n,cmp);
	long long tot=0,ans=0;
	for(int i=1;i<=m+n*k;i++)
	{
		long long x=find(q[i].u),y=find(q[i].v);
		if(x!=y)
		{
			join(x,y);
			ans+=q[i].w;
			tot++;
			if(tot==n+k-1)
			{
				cout<<ans<<endl;
				return 0;
			}
		}
	}
}

