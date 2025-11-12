#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e4+5;
int n,m,k,ans=INT_MAX;
vector<int> a[MAXN];
bool vis[MAXN];
map<int,int> mon[MAXN];
struct node{
	int u,v,h;
};
vector<node> bian;
int root[MAXN];
void slove();
int find(int x){
	if(root[x]==x) return x;
	return find(root[x]);
}
void meg(int x,int y){
	int uu=find(x),vv=find(y);
	if(uu!=vv){
		root[uu]=vv;
	}
	return ;
}
void dfs(int x,int cnt){
	if(x>=bian.size()){
		int f=0;
		int sum=find(1);
		for(int i=2;i<=n;i++){
			int ttttt=find(i);
			if(ttttt!=sum) f=1;
		}
		if(!f){
			ans=min(ans,cnt);
		}
		return ;
	}	
	dfs(x+1,cnt);
	int tutu=find(bian[x].u),tvtv=find(bian[x].v);
	meg(bian[x].u,bian[x].v);
	dfs(x+1,cnt+bian[x].h);
	root[tutu]=tutu;
	root[tvtv]=tvtv;
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
//	cin>>T;
	while(T--){
		slove();
	}
	return 0;
}
void slove(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		root[i]=i;
	}
	for(int i=1;i<=m;i++){
		int l,r,c;
		cin>>l>>r>>c;
		a[l].push_back(r);
		a[r].push_back(l);
		mon[l][r]=c;
		mon[r][l]=c;
		bian.push_back({l,r,c});
	}
	for(int i=1;i<=k;i++){
		int ttt;
		cin>>ttt;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
		}
	}
	for(int i=0;i<bian.size();i++){
		dfs(i,0);
	}
	cout<<ans;
	return ;
}
