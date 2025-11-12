#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const long long maxn=1e4+10;
const long long maxm=1e6+10;
struct ED{
	long long u,v,w;
};
long long n,m,k,ff[maxn<<1],d,ans,a[20][maxn],c[20];
ED edge[maxm],l[maxn],r[maxn*20];
bool cmp(ED a,ED b){
	return a.w<b.w;
}
long long find(long long x){return ff[x]==x?x:ff[x]=find(ff[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		edge[i].u=u;
		edge[i].v=v;
		edge[i].w=w;
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(edge+1,edge+1+m,cmp);
	for(long long i=1;i<=n;i++)ff[i]=i;
	long long p=0;
	while(d<n-1){
		++p;
		long long u=edge[p].u,v=edge[p].v,w=edge[p].w;
		long long fu=find(u),fv=find(v);
		if(fu!=fv){
			ff[fu]=fv;
			d++;
			l[d]=((ED){u,v,w});
			ans+=w;
		} 
	}
	for(long long i=1;i<1<<k;i++){
		long long g=i,h=1,an=0,s=0;
		for(long long i=1;i<n;i++)r[i]=l[i];
		long long cnt=n-1;
		while(g){
			if(g&1){
				an+=c[h];
				for(long long j=1;j<=n;j++){
					r[++cnt]=((ED){h+n,j,a[h][j]});
				}
				ff[h+n]=h+n;
				s++;
			}
			g>>=1;
			h++;
		}
		for(long long i=1;i<=n;i++)ff[i]=i;
		d=0,p=0;
		sort(r+1,r+cnt+1,cmp);
		while(d<n+s-1){
			++p;
			long long u=r[p].u,v=r[p].v,w=r[p].w;
			long long fu=find(u),fv=find(v);
			if(fu!=fv){
				ff[fu]=fv;
				an+=w;
				d++;
			}
		}
		ans=min(ans,an);
	}
	cout<<ans;
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
