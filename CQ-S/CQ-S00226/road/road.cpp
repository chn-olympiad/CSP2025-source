#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k;
int u,v,w;
const int M=1e6+25;
const int N=1e4+25;
int c[M];
struct edge {
	int to,w;
};
struct node {
	int u,v,w;
};
bool cmp(node x,node y){
	return x.w<y.w;
}
vector <node > bian;
int fa[N];
void init(){
	for(int i=1;i<=n+15;i++){
		fa[i]=i;
	}
}
int find_set(int x){
	if(fa[x]!=x){
		return fa[x]=find_set(fa[x]);
	} else {
		return fa[x];
	}
}
void add(int x,int y){
	int temp1=find_set(x);
	int temp2=find_set(y);
	if(temp1!=temp2){
		fa[temp1]=temp2;
	}
}
int a[15][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	7 7 0
//1 2 3
//1 3 4
//2 4 5
//3 4 6
//3 5 7
//4 5 1
//5 7 2
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		bian.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			bian.push_back({i+n,j,a[i][j]});
		} 
	}
	int ans=0;
	init();
	sort(bian.begin(),bian.end(),cmp);
	for(auto it:bian){
		int u=it.u;
		int v=it.v;
		int w=it.w;
		if(find_set(u)!=find_set(v)){
			add(u,v);
			if(u>n){
				ans+=c[u-n];
			}
			if(v>n){
				ans+=c[v-n];
			}
			ans+=w;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
