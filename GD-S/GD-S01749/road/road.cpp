#include<bits/stdc++.h>
using namespace std;
const int N = 3e6+9;
typedef long long ll;

int fa[100009];

int get(int x){
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}

void merge(int u,int v){
	fa[get(u)] = fa[get(v)];
	return;
}

//struct node{
//	int v,w;
//};

struct Edge{
	int u,v,w;
};
vector<Edge>a;

//vector<node>g[N];

struct crys{
	bool ok = 0;int val;
};
crys c[N];
int n,m,k;
ll ans = 0;



int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	
	for(int i = 1;i <= n + k + 10;i++){
		fa[i] = i;
	}
	
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		a.push_back({u,v,w});
		a.push_back({v,u,w});
	}
	
	for(int j = 1;j <= k;j++){
		int c;
		cin >> c;
		//c[j + n].val = c;
		for(int i = 1;i <= n;i++){
			int w;
			cin >> w;
			a.push_back({j + n,i,w});
			a.push_back({i,j + n,w});			
		}
	}
	
	int g = a.size();
	
	sort(a.begin(),a.end(),[&](Edge p,Edge r){
		return p.w < r.w;
	});
	
	ll ans = 0;
	
	for(auto it:a){
		int u = it.u,v = it.v,w = it.w;
		if(get(u) != get(v)){
			ans += w;
			merge(u,v);
			get(u);get(v);
		}
	}
	
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

