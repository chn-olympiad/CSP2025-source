#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=2e6+10;
namespace zyh{
	struct ccf{
		int u,v,w;
		friend bool operator<(ccf pre,ccf nxt){
			return pre.w<nxt.w;
		}
	}e[N],te[N],ztl[N],xld[11][N];
	int fa[N];
	int find(int x){return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
	int c[11];
	int n,m,k;
	ll ans;
	ll sol(int x){
		ll res=0;
		int cnt=0;
		for(int i=1;i<=m;i++) te[i]=e[i];
//		cout<<x<<":\n";		
		for(int i=1;i<=k;i++){
			if(x&(1<<(i-1))){
				res+=c[i];
				merge(te+1,te+m+cnt*n+1,xld[i]+1,xld[i]+n+1,ztl+1);
				cnt++;
//				for(int j=1;j<=n;j++){
//					cout<<xld[i][j].w<<' ';
//				}
//				cout<<'\n';
				for(int j=1;j<=m+cnt*n;j++){
					
					te[j]=ztl[j];
//					cout<<te[j].w<<' ';
				}
//				cout<<'\n';
			}
		} 
		iota(fa+1,fa+n+k+1,1);
		if(res>ans) return INF;
		for(int i=1;i<=m+cnt*n;i++){
			int fu=find(te[i].u),fv=find(te[i].v);
			if(fu==fv) continue;
//			cout<<te[i].u<<' '<<te[i].v<<' '<<te[i].w<<'\n';
			fa[fu]=fv;
			res+=te[i].w;
			if(res>ans) return INF;
		}
//		cout<<res<<'\n';
		return res;
	}
	bool flag=1;
	signed lqr(){
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w; 
		for(int i=1;i<=k;i++){
			cin>>c[i];
			if(c[i]) flag=0;
			for(int j=1;j<=n;j++){
				cin>>xld[i][j].w;
				if(xld[i][j].w) flag=0;
				xld[i][j].u=n+i;
				xld[i][j].v=j;
			}
			sort(xld[i]+1,xld[i]+n+1);
		}
		if(flag){
			cout<<"0";
			return 0;
		}
		sort(e+1,e+m+1);
		if(!k){
			iota(fa+1,fa+n+1,1);
//			for(int i=1;i<=n;i++){
//				cout<<fa[i]<<' ';
//			}
//			cout<<'\n';
			for(int i=1;i<=m;i++){
				int fu=find(e[i].u),fv=find(e[i].v);
//				cout<<e[i].u<<' '<<e[i].v<<'\n';
				if(fu==fv) continue;
				fa[fu]=fv;
				ans+=e[i].w;
			}
			
		}else{
			ans=INF;
			for(int i=0;i<(1<<k);i++) ans=min(ans,sol(i));
		}
		cout<<ans;
		return 0;
	}
}
void file_io(string str){
	string s1=str+".in",s2=str+".out";
	freopen(s1.c_str(),"r",stdin);
	freopen(s2.c_str(),"w",stdout);
}
signed main(){
	file_io("road");
	return zyh::lqr();
}
