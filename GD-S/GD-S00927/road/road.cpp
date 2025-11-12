#include<bits/stdc++.h>
using namespace std;

#define LL long long

void read(LL &x){
	scanf("%lld",&x);
}

void write(LL x){
	printf("%lld\n",x);
}

void write(LL x,LL op){
	if(!op) printf("%lld ",x);
	else printf("%lld\n",x);
}

const LL N=1e4+10,K=11,M=1e6+10,INF=1e18;

LL n,m,k,c[K],a[K][N];

struct Edge{
	LL u,v,w;
}edge[M+N*K];

LL cnt;

bool bl[N+K];

LL f[N+K],siz[N+K];

bool cmp(Edge x,Edge y){
	return x.w<y.w;
}

LL find(LL x){
	return f[x]==x?x:f[x]=find(f[x]);
}

void merge(LL x,LL y){
	x=find(x),y=find(y);
	if(x==y) return ;
	if(siz[x]>siz[y]) swap(x,y);
	f[x]=y;
	siz[y]+=siz[x];
}

bool check(LL x,LL y){
	return find(x)==find(y);
}

LL st[K+1];

LL calc(){
//	sort(edge+1,edge+cnt+1,cmp);
	LL sz=m;
	for(LL i=n+1;i<=n+k;i++) if(bl[i]) sz+=n;
	for(LL i=1;i<=n+k;i++){
		if(bl[i]) f[i]=i,siz[i]=1;
	}
	LL sum=0;
	for(LL i=1;i<=k+1;i++) st[i]=0;
	while(sz--){
		LL op=0,mn=INF,idd=0;
		if(st[k+1]<m){
			op=k+1;
			mn=edge[st[k+1]+1].w;
			idd=st[k+1]+1;
		}
		for(LL i=1;i<=k;i++){
			if(!bl[i+n]) continue;
			LL nw=m+(i-1)*n+st[i]+1;
			if(st[i]<n&&edge[nw].w<mn){
				op=i;
				mn=edge[nw].w;
				idd=nw;
			}
		}
//		printf("debug :%lld %lld %lld\n",op,idd,sum);
		st[op]++;
		if(check(edge[idd].u,edge[idd].v)) continue;
		sum+=edge[idd].w;
		merge(edge[idd].u,edge[idd].v);
	}
	return sum;
}

void solve(){
	read(n),read(m),read(k);
	for(LL i=1;i<=m;i++){
		LL u,v,w;
		read(u),read(v),read(w);
		edge[i].u=u;
		edge[i].v=v;
		edge[i].w=w;
	}
	sort(edge+1,edge+m+1,cmp);
	cnt=m;
	for(LL i=1;i<=k;i++){
		read(c[i]);
		for(LL j=1;j<=n;j++) read(a[i][j]);
		for(LL j=1;j<=n;j++){
			edge[++cnt].u=i+n;
			edge[cnt].v=j;
			edge[cnt].w=a[i][j];
		}
		sort(edge+cnt-n+1,edge+cnt+1,cmp);
	}
	for(LL i=1;i<=n;i++) bl[i]=1;
	LL S=1<<k,ans=INF;
	if(k>5){
		for(LL i=S-1;i<=S-1;i++){
			LL sum=0;
			for(LL j=0;j<k;j++){
				if((i>>j)&1){
					sum+=c[j+1];
					bl[j+1+n]=1;
				}
				else bl[j+1+n]=0;
			}
			ans=min(ans,calc()+sum);
		}
		write(ans);
		return ;
	}
	for(LL i=0;i<S;i++){
		LL sum=0;
		for(LL j=0;j<k;j++){
			if((i>>j)&1){
				sum+=c[j+1];
				bl[j+1+n]=1;
			}
			else bl[j+1+n]=0;
		}
		ans=min(ans,calc()+sum);
	}
	write(ans);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	LL T=1;
//	read(T);
	while(T--){
		solve();
	}
	return 0;
}

