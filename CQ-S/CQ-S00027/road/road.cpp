#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define db double
#define fi first
#define se second
#define MP make_pair
#define pb push_back
#define low lower_bound
#define upp upper_bound
using namespace std;
namespace hwq{
	inline int read(){int x=0;bool f=0;char ch=getchar();while(!isdigit(ch)&&ch!='-') ch=getchar();if(ch=='-') f=1,ch=getchar();while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-48,ch=getchar();return f?-x:x;}
	random_device R;
	mt19937 G(R());
	inline ll rd(ll l,ll r){return uniform_int_distribution<ll>(1ll,1ll<<62)(G);}
	const int MAXN=1e4+15;
	const int MAXM=1e6+5;
	int n,m,K;
	int fa[MAXN],id[MAXN],c[15],t[15];
	struct edge{
		int x,y,w;
		bool operator<(const edge &a)const{return w<a.w;}
	}E[MAXM];
	struct node{
		int x,w;
		bool operator<(const node &a)const{return w<a.w;}
	}a[15][MAXN];
	inline int get_fa(int u){return !fa[u]?u:(fa[u]=get_fa(fa[u]));}
	#define Pair pair<int,int>
	priority_queue<Pair>pq;
	int main(){
		n=read(),m=read(),K=read();
		for(int i=1;i<=m;i++) E[i].x=read(),E[i].y=read(),E[i].w=read();
		for(int i=1;i<=K;i++){
			c[i]=read();
			for(int j=1;j<=n;j++) a[i][j]={j,read()};
		}
		for(int i=1;i<=K;i++) sort(a[i]+1,a[i]+n+1);  
		sort(E+1,E+m+1);
		ll Ans=0;
		int tot=0;
		auto merge=[&](int x,int y){x=get_fa(x),y=get_fa(y);return x==y?0:(fa[y]=x,1);};
		for(int i=1;i<=m;i++) if(merge(E[i].x,E[i].y)) id[++tot]=i,Ans+=E[i].w;
		auto Solve=[&](int s){
			while(!pq.empty()) pq.pop();
			ll ans=0;
			int tn=n;
			for(int i=1;i<=K;i++) if(s&(1<<(i-1))) tn++,ans+=c[i],t[i]=1,pq.push(MP(-a[i][1].w,i));
			if(ans>=Ans) return Ans;
			for(int i=1;i<=n+K;i++) fa[i]=0;
//			printf("solve(%d)\n",s);
			for(int i=1;i<=tot&&tn>1&&ans<Ans;i++){
				while(!pq.empty()&&-pq.top().fi<E[id[i]].w){
					int x=pq.top().se;
					pq.pop();
					if(merge(a[x][t[x]].x,n+x)) tn--,ans+=a[x][t[x]].w;//printf("merge(%d,%d) %lld\n",a[x][t[x]].x,x,ans);
					if(t[x]<n) pq.push(MP(-a[x][++t[x]].w,x));
				}
				if(merge(E[id[i]].x,E[id[i]].y)) tn--,ans+=E[id[i]].w;//printf("merge(%d,%d) %lld\n",E[id[i]].x,E[id[i]].y,ans);
			}
			return ans;
		};
		for(int s=1;s<(1<<K);s++) Ans=min(Ans,Solve(s));
		printf("%lld",Ans);
		return 0;
	}
}
int main(){
//	while(1) //13
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	hwq::main();
	return 0;
}
/*
如果没有K就是最小生成树
K较小的话，可以对K个城市的选与不选枚举
性质A：肯定会选择K个城市，然后做最小生成树
不会！！！完啦
如果我们选择了一个城市，我们其实是在干什么？
花费c_i把它与其它n个点的代价减少c_i
可以先把m条边变为n-1条边
再像K较小的做法那样枚举
复杂度1024*n*K
这能过吗？冲！ 
太危险了吧，但我想不出来了，我也不知道我怎么敢的，呵呵 
跑得莫名其妙的快，就这样吧，被卡常我也认了 
*/
