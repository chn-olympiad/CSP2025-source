#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+100;
int sum,n,m,k,fa[N],sz[N];
int c[20],more[20],mrcnt[20];
struct E{int u,v,w;};
bool operator < (const E &a,const E &b){return a.w<b.w;}
vector<E> e;

int find(int x){return (fa[x]==x?x:fa[x] = find(fa[x]));}
void init(){
	for(int i = 1;i <= n+k;i ++){
		sz[i] = 1;
		fa[i] = i;
	}
}
void merge(int x,int y){
	int fx = find(x),fy = find(y);
	if(sz[fx]<sz[fy])swap(fx,fy);
	sz[fx]+=sz[fy];
	fa[fy] = fx; 
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int u,v,w;
	init();
	for(int i = 1;i <= m;i ++){
		cin >> u >> v >> w;
		e.push_back({u,v,w});
	}
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++){
			cin >> w;
			e.push_back({n+i,j,w+c[i]});
		}	
	}
	sort(e.begin(),e.end());
	int cnt = 0;
	for(int i = 0;cnt < n+k-1 && i < e.size();i ++){
		int u = e[i].u,v = e[i].v,w = e[i].w;
		if(find(u)!=find(v)){
			if(u > n){
				mrcnt[u-n]++;
				more[u-n]+=w;	
			}
			merge(u,v);
			sum += w;
			cnt ++;
		}
	}	
	for(int i = 1;i <= k;i ++){
		if(mrcnt[i]>1)sum-=(mrcnt[i]-1)*c[i];
		else sum-=more[i];
	}
	cout << sum;
	return 0;
}
