#include<bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rd(time(0));
const int M=1e6+5,N=2e5;
int read(){int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x; 
}
int n,m,k,f[N],c[N],cnt;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool merge(int u,int v){
	if((u=find(u))==(v=find(v)))return 0;
	return f[v]=u,1;
}
void init(){
	for(int i=1;i<=n+k;i++)f[i]=i;
}
struct node{int u,v,w;bool operator < (node x){return w<x.w;}}e[M],E[N];
ll sol(int s){init();
	ll res=0;
	for(int i=1;i<=k;i++)if((s>>i-1)&1)res+=c[i];
	for(int i=1;i<=cnt;i++){
		if(E[i].v>n&&!((s>>E[i].v-n-1)&1))continue ;
		if(merge(E[i].u,E[i].v))res+=E[i].w;
	}
	return res;	
}
int main(){
	freopen("road.in","r",stdin);	
	freopen("road.out","w",stdout);	
	n=read(),m=read(),k=read();
	for(int i=1,x,y,z;i<=m;i++)x=read(),y=read(),z=read(),e[i]={x,y,z};
	sort(e+1,e+m+1);
	ll ans=0;
	init(); 
	for(int i=1;i<=m;i++)if(merge(e[i].u,e[i].v))E[++cnt]=e[i],ans+=e[i].w;
	for(int i=1,x;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)x=read(),E[++cnt]={j,i+n,x};
	}
	sort(E+1,E+cnt+1);
	for(int s=1;s<(1<<k);s++)ans=min(ans,sol(s));
	printf("%lld\n",ans);
	return 0;
}

