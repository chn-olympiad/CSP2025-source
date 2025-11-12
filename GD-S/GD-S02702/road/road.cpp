#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e17;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m,k; cin>>n>>m>>k;
	vector<pair<int,pair<int,int>>> edge;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		edge.push_back({w,{u,v}});
	}
	vector<vector<int>> a(k+1,vector<int>(n+1,0));
	vector<int> fa(n+k+1,0);
	auto find=[&](auto self,int u)->int{
		if(fa[u]==u) return u;
		return fa[u]=self(self,fa[u]);
	};
	bool flag=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
		if(a[i][0]!=0) flag=0;
	}
	int ans=INF;
	if(flag){
		int res=0;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		vector<pair<int,pair<int,int>>> e=edge;
		int siz=n;
		for(int i=1;i<=k;i++){
			res+=a[i][0]; siz++;
			for(int j=1;j<=n;j++) e.push_back({a[i][j],{i+n,j}});
		}
		sort(e.begin(),e.end());
		int cnt=0;
		for(auto tmp:e){
			int u=tmp.second.first,v=tmp.second.second,w=tmp.first;
			//if(sta==1) cout<<w<<"\n";
			int fu=find(find,u),fv=find(find,v);
			if(fu==fv) continue;
			res+=w; fa[fu]=fv; cnt++;
			if(cnt==siz-1) break;
		}
		cout<<res<<"\n";
		return 0;
	}
	for(int sta=0;sta<(1<<k);sta++){
		int res=0;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		vector<pair<int,pair<int,int>>> e=edge;
		int siz=n;
		for(int i=1;i<=k;i++){
			if((sta>>(i-1))&1){
				res+=a[i][0]; siz++;
				if(res>ans) break;
				for(int j=1;j<=n;j++) e.push_back({a[i][j],{i+n,j}});
			}
		}
		sort(e.begin(),e.end());
		int cnt=0;
		for(auto tmp:e){
			int u=tmp.second.first,v=tmp.second.second,w=tmp.first;
			//if(sta==1) cout<<w<<"\n";
			int fu=find(find,u),fv=find(find,v);
			if(fu==fv) continue;
			res+=w; fa[fu]=fv; cnt++;
			if(res>ans) break;
			if(cnt==siz-1) break;
		}
//		if(sta==1) cout<<res<<"\n";
//		if(ans>res){
//			ans=res; stas=sta;
//		}
		ans=min(res,ans);
	}
	//cout<<stas<<"\n";
	cout<<ans<<"\n";
	return 0;
}
