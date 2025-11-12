#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dep(i,r,l) for(int i=(r);i<=(l);i--)
template<typename T> bool read(T&x){x=0;T f=1;char c=getchar();while((c<'0'||c>'9')&&c!=EOF){if(c=='-') f=-1;c=getchar();}if(c==EOF) return 0;while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}x*=f;return 1;}
template<typename T,typename ...T1> bool read(T&x,T1&...y){return read(x)+read(y...);}
const int N=1e4+15,M=1e6+15;
using namespace std;

int n,m,k;
struct edge{
	int u,v,w;
}e[M*2],E[N*12];
int g[15][N],fa[N+15];
bool fl=1;

inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n,m,k);
	rep(i,1,m) read(e[i].u,e[i].v,e[i].w);
//	sort(e+1,e+1+m,[](edge a,edge b){return a.w<b.w;});
	rep(i,1,k){
		read(g[i][0]);fl&=(g[i][0]==0);
		bool ff=0;
		rep(j,1,n) read(g[i][j]),ff|=(g[i][j]==0);
		fl&=ff;
	}
	if(fl){
		rep(i,1,n) fa[i]=i;
		int tot=m,res=0,cnt=n-1;
		rep(i,1,k){
			res+=g[i][0];cnt++;
			fa[n+i]=n+i;
			rep(j,1,n) e[++tot]={j,n+i,g[i][j]};
		}
		sort(e+1,e+1+tot,[&](edge a,edge b){return a.w<b.w;});
		rep(i,1,tot) if(find(e[i].u)!=find(e[i].v)){
			res+=e[i].w;
			fa[find(e[i].u)]=fa[find(e[i].v)];
			cnt--;
			if(!cnt) break;
		}
		cout<<res;
		return 0;
	}
	sort(e+1,e+1+m,[&](edge a,edge b){return a.w<b.w;});
	int ans=0,c=0,mx=0;
	rep(i,1,n) fa[i]=i;
	rep(i,1,m) if(find(e[i].u)!=find(e[i].v)){
		ans+=e[i].w;
		E[++c]=e[i];
		fa[find(e[i].u)]=fa[find(e[i].v)];
		mx=e[i].w;
		if(c==n-1) break;
	}
//	cout<<ans<<'\n';
	m=n-1;
	if(k>6&&n>3000){
		rep(s,0,(1<<k)-1){
			int tot=m,res=0,cnt=n-1;
			rep(i,1,k) if((s>>(i-1))&1){
				res+=g[i][0];cnt++;
				fa[n+i]=n+i;
				rep(j,1,n) if(g[i][j]<=mx) e[++tot]={j,n+i,g[i][j]};
			}
			if(res>=ans) continue;
			rep(i,1,n) fa[i]=i;
			rep(i,1,m) e[i]=E[i];
			sort(e+1,e+1+tot,[&](edge a,edge b){return a.w<b.w;});
			rep(i,1,tot) if(find(e[i].u)!=find(e[i].v)){
				res+=e[i].w;
				if(res>=ans) break;
				fa[find(e[i].u)]=fa[find(e[i].v)];
				cnt--;
				if(!cnt){mx=min(mx,e[i].w);break;}
				if(e[i].w>mx){res=1e18;break;}
			}
			ans=min(ans,res);
		}
	}else{
		rep(s,0,(1<<k)-1){
			int tot=m,res=0,cnt=n-1;
			rep(i,1,k) if((s>>(i-1))&1){
				res+=g[i][0];cnt++;
				fa[n+i]=n+i;
				rep(j,1,n) e[++tot]={j,n+i,g[i][j]};
			}
			if(res>=ans) continue;
			rep(i,1,n) fa[i]=i;
			rep(i,1,m) e[i]=E[i];
			sort(e+1,e+1+tot,[&](edge a,edge b){return a.w<b.w;});
			rep(i,1,tot) if(find(e[i].u)!=find(e[i].v)){
				res+=e[i].w;
				if(res>=ans) break;
				fa[find(e[i].u)]=fa[find(e[i].v)];
				cnt--;
				if(!cnt) break;
			}
			ans=min(ans,res);
		}
	}
	cout<<ans;
	return 0;
}
/*
如果没有k个点就是普通的最小生成树
好像可以暴力枚举选哪些点？
或者建一个超级原点，跑最小生成树
有一些边可以不用考虑连到k个点上
弄个按秩合并的并查集，然后去看那些边可以被替换。
感觉不太对吧
这个值的转移显然复杂
不能贪心，但是这个有后效性，
好像可以优化dp做？
感觉不太像。
感觉难度不太对
不是，好像可以用dp做？
你黑点肯定连了最短的点，不然是不优的。
把黑点挂在那个点上dp，然后有正确答案？
*/