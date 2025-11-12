#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+5,N=1e4+15;
struct edge{int u,v;ll w;}e[1<<10][N<<1],p[M],E[15][N];
bool vis[M];
int f[N],n,m,k;
ll c[15],a[15][N],ans;
bool cmp(edge A,edge B){return A.w<B.w;}
void heb(edge *e,int mid,int m){
	int i(1),j(mid+1),k(1);
	while(i<=mid&&j<=m){
		if(cmp(e[i],e[j]))p[k++]=e[i++];
		else p[k++]=e[j++];
	}
	while(i<=mid)p[k++]=e[i++];
	while(j<=m)p[k++]=e[j++];
	for(int i=1;i<=m;++i)
		e[i]=p[i];
}
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void hb(int u,int v){f[gf(u)]=gf(v);}
void init(){for(int i=1;i<=n+k;++i)f[i]=i;}
void find(edge *e,int m){
	init();
	for(int i=1;i<=m;++i){
		if(gf(e[i].u)==gf(e[i].v)){
			vis[i]=0;
			continue;
		}
		vis[i]=1;
		hb(e[i].u,e[i].v);
	}
	for(int i=1,nw(0);i<=m;++i)
		if(vis[i])e[++nw]=e[i];
	return;
}
int read(){
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	int x(0);
	do x=(x<<1)+(x<<3)+(ch^48),ch=getchar();while(isdigit(ch));
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i)
		p[i].u=read(),p[i].v=read(),p[i].w=read();
	sort(p+1,p+1+m,cmp);
	find(p,m);
	for(int i=1;i<n;++i)
		e[0][i]=p[i],ans+=p[i].w;
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j){
			ll w(read());
			E[i][j]={i+n,j,w};
		}
		sort(E[i]+1,E[i]+1+n,cmp);
	}
	for(int s=1;s<(1<<k);++s){
		ll sum(0);
		int tot(0);
		for(int i=0;i<k;++i)
			if((s>>i)&1)sum+=c[i+1],++tot;
		m=(n<<1)+tot-2;
		for(int i=k-1;i>=0;--i)
			if((s>>i)&1){
				int ts=s-(1<<i);
				for(int j=1;j<n+tot-1;++j)
					e[s][j]=e[ts][j];
				for(int j=n+tot-1;j<=m;++j)
					e[s][j]=E[i+1][j-(n+tot-1)+1];
				break;
			}
		heb(e[s],n+tot-2,m);
		find(e[s],m);
		for(int i=1;i<n+tot;++i)
			sum+=e[s][i].w;
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
} 
