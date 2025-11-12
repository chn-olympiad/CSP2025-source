#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+115;
struct node {
	int u,v,w;
};
vector<node> g;
int fa[N];
int n,m,k,ans;
bool cmp(node a,node b){
	return a.w<b.w;
}
int c[100];
void init(){
	for(int i=1;i<=n+10;i++) fa[i]=i;
} 
int find_fa(int x){
	if(x==fa[x]) return x;
	fa[x]=find_fa(fa[x]);
	return fa[x];
}
void unionn(int x,int y){
	int x_fa=find_fa(x);
	int y_fa=find_fa(y);
	fa[x_fa]=fa[y_fa];
}
int cc[N],st;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g.push_back({x,y,z});
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>c[i-n];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			g.push_back({i,j,w});
		}
	}
	int num=0;
	init();
	sort(g.begin(),g.end(),cmp);
	for(int i=0;i<=g.size();i++){
		int x=g[i].u,y=g[i].v,z=g[i].w;
		//cout<<x<<" "<<y<<" "<<z<<endl;
		if(find_fa(x)!=find_fa(y)){
			if(x>n&&cc[x]==0) st++,ans+=c[n-x];
			if(y>n&&cc[y]==0) st++,ans+=c[n-y];
			cc[x]++,cc[y]++;
			
			unionn(x,y);
			ans+=z;
			num++;
		}
		if(num==n+st-1) break;
	}
	cout<<ans;
}