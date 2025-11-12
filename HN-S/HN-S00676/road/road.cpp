#include<bits/stdc++.h>
#define int long long
using namespace std;
struct _queue{
	int a[1000005],head=1,tail;
	int _front(){return a[head];}
	bool _empty(){return tail<head;}
	void _push(int x){a[++tail]=x;}
	void _pop(){head++;}
};
struct _stack{
	int a[1000005],head;
	int _top(){return a[head];}
	bool _empty(){return head;}
	void _push(int x){a[++head]=x;}
	void _pop(){head--;}
};
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
const int N=1e4+5,M=1e6+5,K=15,inf=1e18;
struct Edge{
	int x,y,w;
}edge[M+N*K];
struct Str{
	int fa[N];
	void init(int x){for(int i=1;i<=x;i++) fa[i]=i;}
	int _find(int x){return fa[x]==x?x:fa[x]=_find(fa[x]);}
	void merge(int x,int y){fa[x]=y;}
}tr;
int n,m,k,tot,ans=inf,c[K]; 
bool f[K];
bool cmp(Edge a,Edge b){return a.w<b.w;}
void dfs(int kx,int ks){
	if(ks>=ans) return ;
	if(kx>k){
		tr.init(n+k);
		int s=0;
		for(int i=1;i<=tot;i++){
			int x=edge[i].x,y=edge[i].y,w=edge[i].w;
			if(y>n&&!f[y-n]) continue ;
			int fx=tr._find(x),fy=tr._find(y);
			if(fx!=fy){
				tr.merge(fx,fy);
				s+=w;
			}
		}
		ans=min(ans,s+ks);
		return ;
	}
	f[kx]=0;
	dfs(kx+1,ks);
	f[kx]=1;
	dfs(kx+1,ks+c[kx]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1,x,y,z;i<=m;i++){
		x=read(),y=read(),z=read();
		edge[++tot]=(Edge){x,y,z};
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int x=read();
			edge[++tot]=(Edge){j,i+n,x};
		}
	}
	sort(edge+1,edge+tot+1,cmp);
	dfs(1,0);
	cout<<ans;
	return 0;
}

