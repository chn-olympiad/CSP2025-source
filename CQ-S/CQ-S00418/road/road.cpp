#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace YSY{
	const int N=1e4+25,M=1e6+5;
	const ll INF=1e15;
	int n,m,k,fa[N],tot,cost[15],szL[1<<5],szR[1<<5];
	struct Edge{
		int u,v,w;
		inline bool operator<(const Edge &t) const {return w<t.w;}
	}e[M],c[15][N];
	Edge ori_cand[N],candL[1<<5][N],candR[1<<5][N];
	Edge cur[N*15],tmp[N*15];
	inline int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
	inline void Print(const Edge &t){
		cout<<t.u<<' '<<t.v<<' '<<t.w<<'\n';
	}
	inline void Main(){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
		sort(e+1,e+m+1);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int f1=Find(e[i].u),f2=Find(e[i].v);
			if(f1!=f2) fa[f1]=f2,ori_cand[++tot]=e[i];
		}
//		cout<<"ori_cand:\n";for(int i=1;i<n;i++) Print(ori_cand[i]);cout<<'\n';
		for(int i=1;i<=k;i++){
			cin>>cost[i];
			for(int j=1;j<=n;j++) cin>>c[i][j].w,c[i][j].u=n+i,c[i][j].v=j;
		}
		int mid=k/2;
		for(int S=0;S<(1<<mid);S++){
			for(int i=1;i<=n+k;i++) fa[i]=i;
			tot=0;
			for(int i=1;i<=mid;i++)
				if(S>>(i-1)&1){for(int j=1;j<=n;j++) cur[++tot]=c[i][j];}
			sort(cur+1,cur+tot+1);
			for(int i=1;i<=tot;i++){
				int f1=Find(cur[i].u),f2=Find(cur[i].v);
				if(f1!=f2) fa[f1]=f2,candL[S][++szL[S]]=cur[i];
			}
		}
		for(int S=0;S<(1<<(k-mid));S++){
			for(int i=1;i<=n+k;i++) fa[i]=i;
			tot=0;
			for(int i=mid+1;i<=k;i++)
				if(S>>(i-mid-1)&1){for(int j=1;j<=n;j++) cur[++tot]=c[i][j];}
			sort(cur+1,cur+tot+1);
			for(int i=1;i<=tot;i++){
				int f1=Find(cur[i].u),f2=Find(cur[i].v);
				if(f1!=f2) fa[f1]=f2,candR[S][++szR[S]]=cur[i];
			}
		}
		ll ans=INF;
		for(int S=0;S<(1<<k);S++){
			int L=S&((1<<mid)-1),R=S>>mid;
			for(int i=1;i<=n+k;i++) fa[i]=i;
			tot=0;
			int p1=1,p2=1,t=0;
			while(p1<=szL[L]){
				while(p2<=szR[R]&&candR[R][p2].w<candL[L][p1].w) tmp[++t]=candR[R][p2++];
				tmp[++t]=candL[L][p1++];
			}
			while(p2<=szR[R]) tmp[++t]=candR[R][p2++];
			p1=1,p2=1;
			while(p1<=t){
				while(p2<n&&ori_cand[p2].w<tmp[p1].w) cur[++tot]=ori_cand[p2++];
				cur[++tot]=tmp[p1++];
			}
			while(p2<n) cur[++tot]=ori_cand[p2++];
//			cout<<L<<' '<<R<<' '<<tot<<'\n'; 
			ll sum=0;
			for(int i=1;i<=tot;i++){
				int f1=Find(cur[i].u),f2=Find(cur[i].v);
				if(f1!=f2) fa[f1]=f2,sum+=cur[i].w;
			}
			for(int i=1;i<=k;i++) if(S>>(i-1)&1) sum+=cost[i];
			ans=min(ans,sum);
		}
		cout<<ans;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	YSY::Main();
	return 0;
}

