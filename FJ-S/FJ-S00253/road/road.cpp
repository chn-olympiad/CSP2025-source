#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int M = 5e6+5,K = 15,N = 1e5+5;
int n,m,k,c[K],fa[N],cnt;
long long ans;
struct Edge{
	int u,v,w;
};
vector<Edge> e;

int Get(int x){
	if(x == fa[x]) return x;
	return fa[x] = Get(fa[x]);
}

void Merge(int x,int y){
	fa[Get(x)] = y;
}

bool Together(int x,int y){
	return Get(x) == Get(y);
}

void Kru(){
	for(int i = 0;i < e.size();i++){
		if(!Together(e[i].u,e[i].v)){
			ans += e[i].w;
			Merge(e[i].u,e[i].v);
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		e.push_back({x,y,z});
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			int a;
			cin >> a;
			e.push_back({n+i,j,a});
		}
	}
	sort(e.begin(),e.end(),
		[](const Edge &x,const Edge &y){
			return x.w < y.w;
		}
	);
	for(int i = 0;i <= e.size();i++){
		fa[i] = i;
	}
	Kru();
	cout << ans;

	return 0;
}
