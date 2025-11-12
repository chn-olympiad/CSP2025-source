#include<bits/stdc++.h>
using namespace std;
const int M=1e6+100,N=1e4+100;
long long c[21];
int fa[N];
struct aaa{
	int x,y;
	long long w;
}b[M],d[N],e[21][N],a[M];
bool cmp(aaa x,aaa y){
	return x.w<y.w;
}
int fin(int x){
	if(fa[x]==x)return x;
	return fa[x]=fin(fa[x]); 
}
int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&b[i].x,&b[i].y,&b[i].w);
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			long long w;
			scanf("%lld",&w);
			e[i][j]=(aaa){j,i+n,w}; 
		}
		sort(e[i]+1,e[i]+n+1,cmp); 
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	int tot=0;
	long long ans=0;
	for(int i=1;i<=m;i++){
		int x=fin(b[i].x),y=fin(b[i].y);
		if(x==y)continue;
		fa[x]=y;
		d[++tot]=b[i];
		ans+=b[i].w;
		if(tot==n-1)break; 
	}
	tot=(1<<k)-1;
	for(int s=0;s<=tot;s++){
		long long sum=0;
		for(int i=1;i<n;i++)b[i]=d[i];
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int now=n-1,o=0;
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				o++;
				sum+=c[i];
				int l=1,r=1,p=0;
				while(l<=now&&r<=n){
					if(b[l].w<=e[i][r].w)a[++p]=b[l++];
					else a[++p]=e[i][r++];
				}
				while(l<=now)a[++p]=b[l++];
				while(r<=n)a[++p]=e[i][r++];
				for(int j=1;j<=p;j++)b[j]=a[j];
				now=p;
			}
		} 
		int rrr=0;
		for(int i=1;i<=now;i++){
			int x=fin(b[i].x),y=fin(b[i].y);
			if(x==y)continue;
			fa[x]=y;
			rrr++;
			sum+=b[i].w;
			if(rrr==o+n-1)break; 
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
