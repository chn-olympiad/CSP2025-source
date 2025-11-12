#include<iostream>
#include<algorithm>
#include<vector>
#define LL long long
using namespace std;

const int kMaxN = 1e4+50;
const int KMaxM = 1e6+10;
const int kMaxK = 12;

struct DSU {
	int n_;
	int fa[kMaxN],s[kMaxN];

	void Init(int n) {
		n_=n;
		for(int i=1; i<=n_; i++) {
			fa[i]=i;
			s[i]=1;
		}
	}

	int GetFather(int x) {
		if(fa[x]==x) {
			return fa[x];
		}
		return fa[x] = GetFather(fa[x]);
	}

	void Merge(int u,int v) {
		u=GetFather(u),v=GetFather(v);
		if(u!=v) {
			if(s[u]>s[v]) {
				s[u]+=s[v];
				fa[v] = u;
			} else {
				s[v]+=s[u];
				fa[u] = v;
			}
		}
	}
} dsu;

struct Edge {
	int u,v,w;
};
vector<Edge> edges,new_e[kMaxK], tree;
int c[kMaxK];

bool cmp(const Edge &lhs,const Edge &rhs) {
	return lhs.w<rhs.w;
}

LL Kruscal(int n,const vector<Edge> &e){
	LL ret=0;
	int tot=0;
	
	dsu.Init(n);
	tree.clear();
	tree.resize(n-1);
	for(int i=0;i<e.size();i++){
		if(dsu.GetFather(e[i].u) != dsu.GetFather(e[i].v)){
			ret += e[i].w;
			dsu.Merge(e[i].u,e[i].v);
			tree[tot++] = e[i];
		}
	}
	return ret;
}

LL ans;

vector<Edge> tmp[kMaxK];

void MergeToTmp(int no){	
	int i,j;
	int tot =0;
	
	tmp[no].clear();
	tmp[no].resize(edges.size()+new_e[no].size());
	for(i=0,j=0;i<edges.size() && j<new_e[no].size();){
		if(edges[i].w<new_e[no][j].w){
			tmp[no][tot++] = edges[i++];
		}else{
			tmp[no][tot++] = new_e[no][j++];
		}
	}
	for(;i<edges.size();i++){
		tmp[no][tot++]=edges[i];
	}
	for(;j<new_e[no].size();j++){
		tmp[no][tot++]=new_e[no][j];
	}
}

vector<Edge> temp[kMaxK];

void DFS(int n,int dep,LL sum){
	if(dep<=0){
		return;
	}
	DFS(n,dep-1,sum);
	temp[dep] = edges;
	for(int i=0;i<new_e[dep].size();i++){
		new_e[dep][i].u=n+1;
	}
	MergeToTmp(dep);
	sum+=c[dep];
	ans = min(ans,sum+Kruscal(n+1,tmp[dep]));
	edges = tree;
	DFS(n+1,dep-1,sum);
	edges = temp[dep];
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	edges.resize(m);
	for(int i=0;i<m;i++){
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		new_e[i].resize(n);
		for(int j=0;j<n;j++){
			new_e[i][j].u=n+i;
			new_e[i][j].v=j+1;
			cin>>new_e[i][j].w;
		}
		sort(new_e[i].begin(),new_e[i].end(),cmp);
	}
	sort(edges.begin(),edges.end(),cmp);
	ans = Kruscal(n, edges);
	edges=tree;
	DFS(n,k,0LL);
	cout<<ans<<"\n";
	return 0;
}
