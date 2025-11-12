#include<bits/stdc++.h>
using namespace std;
const int N=1e4+25;
const int M=1e6+25;
const int K=12;
int n,m,k,cnt,f[N],c[K];
long long res,ans;
struct node{
	int u,v,w;
};
node d[M],e[N],a[K][N],fn[N*K],gn[N*K];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void gsort(int x){
	int i=1,j=1,k=1;
	while(i<=cnt&&j<=n){
		if(fn[i].w<a[x][j].w) gn[k++]=fn[i++];
		else gn[k++]=a[x][j++];
	}
	while(i<=cnt) gn[k++]=fn[i++];
	while(j<=n) gn[k++]=a[x][j++];
	cnt+=n;
	for(int i=1;i<=cnt;i++) fn[i]=gn[i];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&d[i].u,&d[i].v,&d[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j].w);
			a[i][j].u=n+i;
			a[i][j].v=j;
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	sort(d+1,d+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		if(find(d[i].u)!=find(d[i].v)){
			f[find(d[i].u)]=find(d[i].v);
			ans+=d[i].w;
			e[++cnt]=d[i];
		}
	}
	for(int s=1;s<1<<k;s++){
		res=0;
		cnt=n-1;
		for(int i=1;i<n;i++) fn[i]=e[i];
		for(int i=1;i<=k;i++) if(s&(1<<i-1)){
			res+=c[i];
			gsort(i);
		}
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<=cnt;i++){
			if(find(fn[i].u)!=find(fn[i].v)){
				f[find(fn[i].u)]=find(fn[i].v);
				res+=fn[i].w;
			}
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
