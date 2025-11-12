#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace xmx{
	const int M=1e6+5;
	const int N=1e5+5;
	struct node{
		int cu,cv,cuv;
		inline bool operator < (const node &ax)const{
			return cuv<ax.cuv;
		}
	}; 
	node v[M];
	int tot;
	node v_[N];
	node v__[N*11];
	int n,m,k;
	int fa[N];
	int ans;
	inline int find(int x){
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	inline void MST(){
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int fa_=find(v[i].cu),fb_=find(v[i].cv);
			if(fa_!=fb_){
				ans+=v[i].cuv;
				fa[fb_]=fa_;
				v_[++tot]=v[i];
			}
		}
	}
	int vis[N];
	int ljb[15][N];
	inline int MST_(){
		int ans_=0;
		for(int i=1;i<=n+10;i++)fa[i]=i;
		for(int i=1;i<=tot;i++)v__[i]=v_[i];
		int tots=tot;
		for(int i=1;i<=10;i++){
			if(vis[i]){
				for(int j=1;j<=n;j++){
					v__[++tots]={n+i,j,ljb[i][j]};
				}
			}
		}
		sort(v__+1,v__+tots+1);
		for(int i=1;i<=tots;i++){
			int fa_=find(v__[i].cu),fb_=find(v__[i].cv);
			if(fa_!=fb_){
				ans_+=v__[i].cuv;
				fa[fb_]=fa_;
			}
		}
		return ans_;
	}
	inline void dfs(int x,int addvals){
		if(x==k+1)return;
		dfs(x+1,addvals);
		vis[x]=1;
		int res=MST_()+addvals+ljb[x][0];
//		cout<<x<<" "<<res<<"xmx\n";
		ans=min(ans,res);
		dfs(x+1,addvals+ljb[x][0]);
		vis[x]=0;
	}
	signed main(){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>v[i].cu>>v[i].cv>>v[i].cuv;
		} 
		for(int i=1;i<=k;i++){
			for(int j=0;j<=n;j++){
				cin>>ljb[i][j];
			}
		}
		sort(v+1,v+m+1);
		MST();
		dfs(1,0);
		cout<<ans;
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	return xmx::main();
}

