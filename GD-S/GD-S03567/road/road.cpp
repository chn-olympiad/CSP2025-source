#include<bits/stdc++.h>
using namespace std;

const int N = 3e4+100;
int n,m,k,c[N],a[15][N],p[N],ans=0,fa[N];
bool h = true;
//vector<ku> g[N];
struct edge{
	int u,v,c;
};
vector<edge> ed;

bool cmp(edge a,edge b){
//	int s1=a.c,s2=b.c;
	return a.c<b.c;
}
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void add(int x,int y){
	fa[x] = y;
	return ;
}

void solve(){
//	int res = n;
//	for(int i = 1; i<=k; i++){
//		res++,m+=n;
//		fa[res] = res;
//		for(int j = 1; j<=n; j++){
//			ed.push_back({res,j,a[i][j]});
//		}
//	}
//cout<<m<<endl;
//	cout<<1<<endl;
	sort(ed.begin(),ed.end(),cmp);
//	cout<<1<<endl;
	for(int i = 0; i<m; i++){
		edge now = ed[i];
		int u=now.u,v=now.v,w=now.c;
		int x=find(u),y=find(v);
//		cout<<1<<endl;
//		cout<<"1111111 "<<u<<" "<<v<<endl;
		if(x == y) continue;
//		cout<<u<<" "<<v<<endl;
		add(x,y);
//		cout<<2<<endl;
		ans += w;
	}
	cout<<ans<<endl;
	return ;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1; i<=m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		ed.push_back({u,v,w});
	}
	if(k == 0) h=false;
	for(int i = 1; i<=k; i++){
		cin>>c[i];
		if(c[i]!=0) h=false;
		for(int j = 1; j<=n; j++){
			cin>>a[i][j];
			if(c[i]!=0) h=false;
		}
	}
	for(int i = 1; i<=n; i++){
		fa[i] = i;
	}
	if(h){
		cout<<0<<endl;
		return 0;
	}
	solve();
	return 0;
} 
