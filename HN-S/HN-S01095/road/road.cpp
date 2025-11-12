#include<bits/stdc++.h>
using namespace std;
void file_init(){
#ifndef LOCAL
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#else
	freopen("road3.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	return;
}
void fast_read(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return;
}
int n,m,k;
const int M=1e6+10;
struct edge{
	int x,y,z;
	bool friend operator<(edge x,edge y){
		return x.z<y.z;
	}
}e[M];
const int N=1e4+20;
int c[N];
const int K=20;
int a[K][N];
void read(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	return;
}
int used;
#define ll long long
ll sum;
vector<edge>dat;
ll ans=LLONG_MAX;
namespace kruskal{
	namespace dsu{
		int fa[N];
		int siz[N];
		void reset(){
			for(int i=1;i<=n+k;i++){
				fa[i]=i;
				siz[i]=1;
			}
			return;
		}
		int find(int x){
			if(fa[x]==x){
				return x;
			}
			return fa[x]=find(fa[x]);
		}
		bool unionn(int x,int y){
			x=find(x);
			y=find(y);
			if(x==y){
				return false;
			}
			if(siz[x]<siz[y]){
				swap(x,y);
			}
			fa[y]=x;
			siz[x]+=siz[y];
			return true;
		}
	}
	vector<edge>g;
	void init(){
		dsu::reset();
		g.clear();
		int i=0,j=1;
		while(i<dat.size()||j<=m){
			if(i<dat.size()&&j<=m){
				if(dat[i].z<e[j].z){
					g.push_back(dat[i++]);
				}
				if(dat[i].z>e[j].z){
					g.push_back(e[j++]);
				}
				if(dat[i].z==e[j].z){
					g.push_back(dat[i++]);
					g.push_back(e[j++]);
				}
			}else if(i<dat.size()){
				g.push_back(dat[i++]);
			}else if(j<=m){
				g.push_back(e[j++]);
			}
		}
		return;
	}
	void work(){
		int cnt=0;
		for(edge e:g){
			if(dsu::unionn(e.x,e.y)){
				//cerr<<e.x<<' '<<e.y<<' '<<e.z<<'\n';
				sum+=e.z;
				if(sum>ans){
					return;
				}
				if(++cnt==n+used-1){
					return;
				}
			}
		}
		//cerr<<"Error!";
		return;
	}
}
bool use[N];
void build(){
	sum=0;
	dat.clear();
	for(int i=1;i<=k;i++){
		if(use[i]){
			//cerr<<i<<' ';
			sum+=c[i];
			for(int j=1;j<=n;j++){
				dat.push_back({i+n,j,a[i][j]});
			}
		}
	}
	//cerr<<sum<<'\n';
	sort(dat.begin(),dat.end());
	return;
}
void solve(int x){
	if(x==k+1){
		build();
		kruskal::init();
		kruskal::work();
		ans=min(ans,sum);
		//cerr<<sum<<'\n';
		return;
	}
	use[x]=false;
	solve(x+1);
	used++;
	use[x]=true;
	solve(x+1);
	used--;
	return;
}
int main(){
	file_init();
	fast_read();
	read();
	sort(e+1,e+m+1);
	solve(1);
	cout<<ans;
	return 0;
}
