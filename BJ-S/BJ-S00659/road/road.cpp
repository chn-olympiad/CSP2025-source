#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
inline int read(){
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
const int N=1e4+100,M=2e6+5;
int n,m,k;
// struct edge{
//     int v,c,next;
// } e[M];
// int h[N],o[N],cnt=0;
// void addedge(int u,int v,int c){
//     e[++cnt]={v,c,h[u]},h[u]=cnt;
// }
struct edge{
	int u,v,c;
	bool operator>(const edge &x)const{
		return c>x.c;
	}
};
vector<edge> g;
int fa[N],c[N],a[15][N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int cnt;
edge e[M];
priority_queue<edge,vector<edge>,greater<edge> > q0,q;// extra edge
int kruskal(int d){
	rep(i,1,n+d) fa[i]=i;
	int c0=0,res=0;
	rep(i,1,n+d-1){
		edge nxt;
		do{
			if(c0>=m){
				nxt=q.top(),q.pop();
				continue;
			}
			if(q.empty()){
				nxt=e[c0],c0++;
				continue;
			}
			if(e[c0].c<q.top().c) nxt=e[c0],c0++;
			else nxt=q.top(),q.pop();
			// cout<<i;
		}while(find(nxt.u)==find(nxt.v));
		// cout<<nxt.u<<" "<<nxt.v<<" "<<nxt.c<<endl;
		res+=nxt.c,fa[find(nxt.u)]=find(nxt.v);
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	rep(i,1,m){
		int u=read(),v=read(),c=read();
		g.push_back({u,v,c}); q0.push({u,v,c});
	}
	while(!q0.empty()){
		edge now=q0.top();
		q0.pop();
		e[++cnt]=now;
	}
	int sumc=0;
	rep(i,1,k){
		c[i]=read();
		sumc+=c[i];
		rep(j,1,n){
			a[i][j]=read();
		}
	}
	if(!sumc){
		rep(i,1,k){
			rep(j,1,n){
				q.push({i+n,j,a[i][j]});
			}
		}
		cout<<kruskal(k);
		return 0;
	}
	int mn=0x3f3f3f3f3f3f3f3fll;
	rep(s,0,(1<<k)-1){
		cout<<s<<endl;
		int ans=0,d=0;
		while(!q.empty()) q.pop();
		rep(i,1,k){
			// cout<<(s>>(i-1)&1)<<" ";
			if((s>>(i-1)&1)){
				d++;
				ans+=c[i];
				rep(j,1,n){
					q.push({i+n,j,a[i][j]});
				}
			}
		}
		ans+=kruskal(d);
		mn=min(mn,ans);
		cout<<ans<<endl;
	}
	printf("%lld\n",mn);
	return 0;
}