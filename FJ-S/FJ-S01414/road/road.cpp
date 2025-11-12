#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5,M=2e6+5,K=15;
struct Edge{
	int x,y,z;
}es[M],et[M];
int n,m,k,t=0,tt=0,tot=0,c[K],fa[N];
bool bt[N],o=1;
int read(){
	int x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int get(int x){
	if(!fa[x])return x;
	return fa[x]=get(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read(),z=read();
		es[++t]=Edge{x,y,z};
	}
	sort(es+1,es+t+1,[](Edge x,Edge y){return x.z<y.z;});
	for(int i=1;i<=t;++i){
		int x=es[i].x,y=es[i].y;
		x=get(x),y=get(y);
		if(x!=y)fa[x]=y,et[++tt]=es[i];
	}
	for(int i=1;i<=k;++i){
		c[i]=read();
		bool fg=1;
		for(int j=1;j<=n;++j){
			int z=read();
			if(!z)fg=0;
			et[++tt]=Edge{n+i,j,z};
		}
		if(c[i]||fg)o=0;
	}
	sort(et+1,et+tt+1,[](Edge x,Edge y){return x.z<y.z;});
	for(int i=1;i<=n;++i)bt[i]=1;
	long long ans=1e18;
	for(int l=(o?(1<<k)-1:0);l<(1<<k);++l){
		long long s=0;
		for(int i=1;i<=n+k;++i)fa[i]=0;
		for(int i=0;i<k;++i)
			if(l>>i&1)s+=c[i+1],bt[n+i+1]=1;
			else bt[n+i+1]=0;
		for(int i=1;i<=tt;++i){
			int x=et[i].x,y=et[i].y,z=et[i].z;
			if(!bt[x]||!bt[y])continue;
//			cout<<"  "<<x<<' '<<y<<' '<<z<<endl;
			x=get(x),y=get(y);
			if(x!=y)fa[x]=y,s+=z;
		}
//		cout<<s<<endl;
		ans=min(ans,s);
	}
	printf("%lld",ans);
	return 0;
}

/*
CSP 2025 RP++!
*/
