#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005,K=15;
int n,m,k,x,y,z,fa[N+K],sz[N+K];ll c[15],ans;
struct Edge{
	int x,y,z;
	friend bool operator<(Edge x,Edge y){return x.z<y.z;}
};
vector<Edge> v[K],nw[K];
void merges(vector<Edge> &res,const vector<Edge> &v,const vector<Edge> &v2){
	int s1=v.size(),s2=v2.size(),i=0,j=0;res.clear(),res.reserve(n<<1);
	while(i<s1&&j<s2){
		if(v[i]<v2[j])	res.emplace_back(v[i++]);
		else	res.emplace_back(v2[j++]);
	}
	while(i<s1)	res.emplace_back(v[i++]);
	while(j<s2)	res.emplace_back(v2[j++]);
}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(vector<Edge> &res,const vector<Edge> &v,const vector<Edge> &v2){
	merges(res,v,v2);
	for(int i=1;i<=n+k;i++)	fa[i]=i,sz[i]=1;
	vector<Edge> tr;tr.reserve(n);
	for(auto p:res){
		int fx=find(p.x),fy=find(p.y);
		if(fx!=fy){
			tr.emplace_back(p);
			if(sz[fx]>sz[fy])	fa[fy]=fx,sz[fx]+=fy;
			else	fa[fx]=fy,sz[fy]+=sz[fx];
		}
	}
	res.swap(tr),tr.clear(),tr.shrink_to_fit();
}
void dfs(int x,ll cst){
	if(x>k){
		for(auto p:nw[x])	cst+=p.z;
		ans=min(ans,cst);return;
	}
	nw[x+1]=nw[x],dfs(x+1,cst);
	merge(nw[x+1],nw[x],v[x]),dfs(x+1,cst+c[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	while(m--)	cin>>x>>y>>z,v[0].emplace_back((Edge){x,y,z});
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>x;
			v[i].emplace_back((Edge){n+i,j,x});
		}
		sort(v[i].begin(),v[i].end());
	}
	sort(v[0].begin(),v[0].end());
	merge(nw[1],v[0],vector<Edge>()),v[0].clear(),v[0].shrink_to_fit();
	ans=LLONG_MAX,dfs(1,0),cout<<ans;
	return 0;
}
