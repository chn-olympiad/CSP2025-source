#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e4+50,M=1e6+5,K=15;
int n,m,k,f[N],cnt[N],c[K],pd[K],la[K];
struct lj {
	int u,v,w;
}a[M],e[M];//e为城市化道路 
bool cmp(lj a,lj b) {
	return a.w<b.w;
}
int fd(int x) {
	if(f[x]==x) return x;
	return f[x]=fd(f[x]);
}
ll sum,ans=1e18;
void add(int u,int v,int w) {
	u=fd(u),v=fd(v);
	if(u==v) return ;
	sum+=w;
	if(cnt[u]<cnt[v]) f[u]=v,cnt[v]+=cnt[u];
	else f[v]=u,cnt[u]+=cnt[v];
} 
void get() {
	sum=0;
	for(int i=1;i<=n+k;i++) f[i]=i,cnt[i]=1;
	for(int i=0;i<k;i++) la[i]=0;
	for(int i=1;i<=m;i++) {
		for(int j=0;j<k;j++) {
			if(!pd[j]) continue ;
			for(int t=la[j]+1;t<=n&&e[j*n+t].w<=a[i].w;t++,la[j]++)  
			    add(e[j*n+t].u,e[j*n+t].v,e[j*n+t].w);
		}
		add(a[i].u,a[i].v,a[i].w);
	}
} 
void dfs(int x,ll s) {
	if(x==k) {
		get();
		ans=min(ans,s+sum);
	//	cout<<s<<" "<<sum<<"\n"; 
		return ;
	}
	pd[x]=1;
	dfs(x+1,s+c[x]);
	if(c[x]>0) {
		pd[x]=0;
		dfs(x+1,s);		
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) 
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	sort(a+1,a+m+1,cmp);
	for(int i=0;i<k;i++) {
		scanf("%d",&c[i]);
	    for(int j=1;j<=n;j++) {
	    	e[i*n+j].u=n+i+1,e[i*n+j].v=j;
	    	scanf("%d",&e[i*n+j].w);
		}
		sort(e+(i*n)+1,e+(i*n)+n+1,cmp);
	}
	dfs(0,0);
	printf("%lld",ans);
	return 0;
}
