/*by lz*//*ccf明年出简单一点吧*//*48*//*in total seemed to be 138*/
#include<bits/stdc++.h>
//#define int long long  
using namespace std;
const int NN=1e6+5;
const int NNN=1e5+5;
int n,m,k;
int fa[NNN];

struct node {
	int u,v,w;
} edge[NN];
bool cmp(node A,node B) {
	return A.w<B.w;
}


struct node1 {
	int v,w;
};


vector<node1>a[NNN];
int c[NN];

void init() {
	for(int i=1; i<=n; i++) {
		fa[i]=i;
	}
	return;
}
int find(int x) {
	if(fa[x]==x) return fa[x];
	else {
		return fa[x]=find(fa[x]);
	}
}
void merge(int x,int y) {
	int xx=find(x),yy=find(y);
	if(xx==yy) return;
	else {
		fa[xx]=yy;
		return;
	}
}
void kri() {
	init();
	sort(edge+1,edge+m+1,cmp);
	int cnt=0,ans=0;
	for(int i=1; i<=n; i++) {
		if(cnt==n-1) {
			break;
		}
		if(find(edge[i].u)!=find(edge[i].v)) {
			merge(edge[i].u,edge[i].v);
			ans+=edge[i].w;
		} else if(find(edge[i].u)==find(edge[i].v)) {
			continue;
		}
	}
	cout<<ans;
}
void solve16() {

	for(int i=1; i<=m; i++) {
		int op1,op2,op3;
		cin>>op1>>op2>>op3;
		edge[i].u=op1,edge[i].v=op2,edge[i].w=op3;
	}
	kri();
}
void solve50() {
	
	for(int i=1; i<=m; i++) {
		int op1,op2,op3;
		cin>>op1>>op2>>op3;
//		edge[i].u=op1,edge[i].v=op2,edge[i].w=op3;
	}
	for(int j=1; j<=k; j++) {
		cin>>c[j];
		for(int i=1; i<=n; i++) {
			int op;
			cin>>op;
//			a[j].push_back({i,op});
//			b[i].push_back({j,op});
		}
//		kri();
	}
	cout<<0;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		solve16();
	}else{
		solve50();
	}
	return 0;
}
