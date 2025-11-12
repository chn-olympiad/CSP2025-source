#include<bits/stdc++.h>
#define int long long
#define For(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
const int N=1e3+10,M=1e7+10;
int n,m,k,a[N],tot,c[20];
int fa[N],mp[N][N],cmp[N][N];
struct edge{int u,v,w,t,ok;}e[M];
int find(int x){
	if(fa[x]==0) return x;
	return fa[x]=find(fa[x]);
}
void add(int u,int v,int w,int t){
	if(w<mp[u][v]){
		mp[u][v]=w;
		cmp[u][v]=t;
	}
	if(w<mp[v][u]){
		mp[v][u]=w;
		cmp[v][u]=t;
	}
}
void mysort(){
	sort(e+1,e+tot+1,[](edge e1,edge e2){
		if(e1.ok==0) return false;
		if(e2.ok==0) return true;
		return e1.w+c[e1.t]<e2.w+c[e2.t];
	});
}
void work1(){
	For(t,1,k){
		c[t]=read();
		For(i,1,n){
			a[i]=read();
			For(j,1,i) add(i,j,a[i]+a[j],t);
		}
	}
	For(i,1,n) For(j,1,i){
		if(mp[i][j]!=1e18)
			e[++tot]={i,j,mp[i][j],cmp[i][j],1};
	}
	int cnt=0,ans=0,flg1=1;
	while(flg1){
		mysort();
		For(i,1,tot){
			int u=e[i].u,v=e[i].v,w=e[i].w+c[e[i].t];
			int t1=find(u),t2=find(v);
			if(t1==t2||e[i].ok==0) continue;
			e[i].ok=0;
			fa[t1]=t2;
			cnt++;
			ans+=w;
			if(c[e[i].t]!=0) {c[e[i].t]=0; break;}
			if(cnt==n-1) {flg1=0; break;}
		}
	}
	
	printf("%lld\n",ans);
}


signed main(){ // >=20pts
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(); m=read(); k=read();
	For(i,1,n) For(j,1,n) mp[i][j]=1e18;
	For(i,1,m){
		int u=read(),v=read(),w=read();
		// e[++tot]={u,v,w};
		add(u,v,w,0);
	}
	work1();
	
	
	
	
	return 0;
}