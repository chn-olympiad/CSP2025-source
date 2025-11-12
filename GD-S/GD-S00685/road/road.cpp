#include<bits/stdc++.h>
using namespace std;
//Ren5Jie4Di4Ling5%
long long ans=INT_MAX,qwq;
long long n,m,k,M;
long long c[20];
long long pre[1000010];
long long w[20][100010];
long long bh[10010];
long long q;
struct F{
	long long x,y,w;
}a[1000010],a2[1000010];
bool cmp(F x,F y){
	return x.w<y.w;
}
long long find(long long x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
long long kru(long long mb,long long m2,long long awa)
{
	for(register int i=0;i<=n+k;++i) pre[i]=i;
	sort(a2+1,a2+1+m2,cmp);
	long long sum=0;
	for(register int i=1;i<=m2;++i)
	{
		if(mb==0) break;
		if(mb>m2-i+1) return INT_MAX;
		long long X=find(a2[i].x),Y=find(a2[i].y);
		if(X!=Y)
		{
			mb--;
			pre[X]=Y;
			sum=sum+a2[i].w;
			if(sum+awa>=ans||sum+awa>=qwq) return INT_MAX;
		}
	}
	if(mb!=0) sum=INT_MAX;
	return sum;
}
void solve()
{
	long long m2=m,sum=0;
	for(register int i=1;i<=m;++i) a2[i]=a[i];
	for(register int i=1;i<=q;++i)
	{
		sum=sum+c[bh[i]];
		if(sum>=ans||sum>=qwq) return;
		for(register int j=1;j<=n;++j) 
		{
			if(w[bh[i]][j]>=qwq||w[bh[i]][j]>=ans) continue;
			a2[++m2]={j,bh[i]+n,w[bh[i]][j]};
		}
	}
	sum=sum+kru(q+n-1,m2,sum);
	ans=min(ans,sum);
}
void DFS(long long i,long long S)
{
	if(S>=ans||S>=qwq) return;
	if(i==k)
	{
		solve();
		return;
	}
	bh[++q]=i+1;
	DFS(i+1,S+c[i+1]);
	q--;
	DFS(i+1,S);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>M>>k;
	for(register int i=1;i<=M;++i)
	{
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[++m]={u,v,w};
	}
	sort(a+1,a+1+m,cmp);
	long long Q=n-1,Z=0;
	for(register int i=1;i<=n;++i) pre[i]=i;
	for(register int i=1;i<=m;++i)
	{
		if(Q==0) break;
		long long X=find(a[i].x),Y=find(a[i].y);
		if(X!=Y)
		{
			pre[X]=Y;
			Q--;
			a[++Z]=a[i];
			qwq=qwq+a[i].w;
		}
	}
	m=Z;
	for(register int i=1;i<=k;++i)
	{
		scanf("%lld",&c[i]);
		for(register int j=1;j<=n;++j) scanf("%lld",&w[i][j]);
		if(c[i]>=qwq) --i,--k;
	}
	DFS(0,0);
	if(ans==INT_MAX) ans=qwq;
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
 2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
