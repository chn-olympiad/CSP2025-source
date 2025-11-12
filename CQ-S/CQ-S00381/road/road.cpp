#include<bits/stdc++.h>
using namespace std;
namespace ld{
	typedef long long ll;
	const int N=1e6+5;
	const int INF=1e9;
	const ll IINF=1e18;
	int n,m,K;
	struct edge{
		int x,y,w;
	}ed[N],ted[N];
	edge mst[1<<10][10025];int kcnt[1<<10];
	bool cmp(edge a,edge b){return a.w<b.w;}
	struct Dsu{
		int fa[N];
		int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
		void init(){
			for(int i=1;i<=n+K;i++)fa[i]=i;
		}
	}dsu;
	void krus(){
		sort(ed+1,ed+1+m,cmp);
		dsu.init();
		for(int i=1;i<=m;i++){
			int bx=dsu.getfa(ed[i].x),by=dsu.getfa(ed[i].y);
			if(bx==by)continue;
			dsu.fa[bx]=by;
			mst[0][++kcnt[0]]=ed[i];
		}
	}
	int c[11];
	struct edge2{
		int x,w;
		bool operator<(const edge2&b)const {
			return w<b.w;
		}
	}a[11][10025];
	int main(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		cin>>n>>m>>K;
		for(int i=1;i<=m;i++)cin>>ed[i].x>>ed[i].y>>ed[i].w;
		krus();
		for(int i=1;i<=K;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++)cin>>a[i][j].w,a[i][j].x=j;
			sort(a[i]+1,a[i]+1+n);
		}	
		for(int st=1;st<(1<<K);st++){
			int lb=__lg(st&(-st));int lst=st^(1<<lb);
			++lb;
			for(int i=1;i<=n;i++)ted[i]={n+lb,a[lb][i].x,a[lb][i].w};
			dsu.init();
			
			int p1=1,p2=1;
			while(p1<=kcnt[lst]&&p2<=n){
				edge now;
				if(mst[lst][p1].w<ted[p2].w)now=mst[lst][p1],++p1;
				else now=ted[p2],++p2;
				int bx=dsu.getfa(now.x),by=dsu.getfa(now.y);
				if(bx==by)continue;
				dsu.fa[bx]=by,mst[st][++kcnt[st]]=now;
			}
			while(p1<=kcnt[lst]){
				edge now=mst[lst][p1];++p1;
				int bx=dsu.getfa(now.x),by=dsu.getfa(now.y);
				if(bx==by)continue;
				dsu.fa[bx]=by,mst[st][++kcnt[st]]=now;
			}		
			while(p2<=n){
				edge now=ted[p2];++p2;
				int bx=dsu.getfa(now.x),by=dsu.getfa(now.y);
				if(bx==by)continue;
				dsu.fa[bx]=by,mst[st][++kcnt[st]]=now;
			}
		}
		ll ans=IINF;
		for(int st=0;st<(1<<K);st++){
			ll res=0;
			for(int i=1;i<=K;i++)if(st>>(i-1)&1)res+=c[i];
			for(int i=1;i<=kcnt[st];i++)res+=mst[st][i].w;
			ans=min(ans,res);
		}
		cout<<ans<<'\n'; 
		
		return 0;
	}
}
int main(){
	ld::main();
	return 0;
}
//空间:150mb/512mb
//时间:s/1s
//大洋里很水，必须要对拍 
//要测速，加启发式 
