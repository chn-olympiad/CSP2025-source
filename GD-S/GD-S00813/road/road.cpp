#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=f;
	return;
}
template<typename T>
inline void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
bool Mbe;
typedef long long ll;
const int N=1e4+15;
const int M=1e6+5;
const int K=11;
int n,m,k,c[K],x,fa[N],p[K],cnt,edg,id;
bool tag[N];
ll ans,ret;
struct edge{
	int u,v,w,id;
	edge(){}
	edge(int _u,int _v,int _w,int _id):u(_u),v(_v),w(_w),id(_id){}	
	bool operator < (const edge& a)const{
		return w<a.w;
	}
};
edge e1[M],e2[M];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kruscal1(){
	for(int i=1;i<=n;++i) fa[i]=i;
	edg=0;
	for(int i=1;i<=m;++i){
		int fu=find(e1[i].u);
		int fv=find(e1[i].v);
		if(fu==fv) continue;
		ans+=e1[i].w;
		fa[fu]=fv;  
		++edg;
		swap(e1[i],e1[edg]);
		if(edg==n-1) break;
	}
}
void merge(){
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=cnt;++i) fa[n+p[i]]=n+p[i];
	int opt1=1,opt2=1,lim=n*k,pl=0;
 	while(opt1<=edg||opt2<=lim){
 		while(opt2<=lim&&!tag[e2[opt2].id]) ++opt2;
//		cout<<"EDGE:"<<opt1<<' '<<opt2<<'\n';
 		if(opt1<=edg&&(opt2>lim||e1[opt1].w<e2[opt2].w)){
 			int fu=find(e1[opt1].u);
			int fv=find(e1[opt1].v);
			if(fu!=fv) ret+=e1[opt1].w,fa[fu]=fv,pl++;  
			++opt1;
		}
		else{
			int fu=find(e2[opt2].u);
			int fv=find(e2[opt2].v);
			if(fu!=fv) ret+=e2[opt2].w,fa[fu]=fv,pl++; 
			++opt2;
		} 
		if(pl==n+cnt-1) break;
	}
}
void solve(){
	read(n);read(m);read(k);
	for(int i=1;i<=m;++i) read(e1[i].u),read(e1[i].v),read(e1[i].w);
	sort(e1+1,e1+m+1);
	for(int i=1;i<=k;++i){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(x);
			e2[++id]=edge(j,n+i,x,n+i);
		}
	}
	sort(e2+1,e2+id+1);
	kruscal1();
	int S=(1<<k)-1;
//	cout<<ans<<'\n';
	for(int i=1;i<=S;++i){
		cnt=ret=0;
		for(int j=1;j<=k;j++) 
			if(i&(1<<j-1)) p[++cnt]=j,ret+=c[j],tag[j+n]=true;
		merge();
//		cout<<i<<' '<<ret<<'\n';
		ans=min(ans,ret);
	  	for(int j=1;j<=k;j++) tag[j+n]=false;
	}
	write(ans);
	putchar('\n');
}
bool Med;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int c=1,T=1;
	while(T--) solve();
//	cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB"<<'\n';
	return 0;
}
/*
O(nk2^k)
*/
