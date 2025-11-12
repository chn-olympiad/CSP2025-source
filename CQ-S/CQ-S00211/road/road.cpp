#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int u,v;
	ll w;
	bool friend operator < (node a,node b){
		return a.w<b.w;
	}
};
int bcj[10110];
int n;
int find(int u){
	if(bcj[u]==u){
		return u;
	}
	return bcj[u]=find(bcj[u]);
}int k;
void scs(vector<node> &in,vector<node> &out){
	for(int i=1;i<=n+k;i++){
		bcj[i]=i;
	}
	for(auto &e:in){
		int fa=find(e.u),fb=find(e.v);
		if(fa==fb){
			continue;
		}
		bcj[fa]=bcj[fb];
		out.push_back(e);
	}
} 

ll a[12][10010];
ll c[10010];
vector<node> vn;
vector<node> t[12];
vector<node> dg[12];
ll ans=LONG_LONG_MAX;
void dfs(int u,ll sum){
	if(u>k){
		ll t=sum;
		for(auto &e:dg[u-1]){
//			cout<<e.u<<" "<<e.v<<" "<<e.w<<"\n";
			
			t+=e.w;
		}
//		cout<<sum<<"================="<<t<<"\n";
		ans=min(ans,t);
		return ;
	}
	t[u]=dg[u-1];
	for(int i=1;i<=n;i++){
		t[u].push_back({i,u+n,a[u][i]});
	}
	sort(t[u].begin(),t[u].end());
	dg[u].clear();
	scs(t[u],dg[u]);
	dfs(u+1,c[u]+sum);
	dg[u]=dg[u-1];
	dfs(u+1,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int m;
	
	cin>>n>>m>>k;
//	double start=clock();
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d%d%d",&u,&v,&w);
		vn.push_back({u,v,w}); 
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	sort(vn.begin(),vn.end());
	
	scs(vn,dg[0]);
	
	dfs(1,0);
	cout<<ans<<"\n";
	
//	double end=clock();
//	cout<<end-start;
	return 0;
}

