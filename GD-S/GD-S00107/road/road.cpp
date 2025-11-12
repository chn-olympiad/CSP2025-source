#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn = 1e6 + 100;
int f[maxn];
struct Edge{
	int u,v,w;
}e[maxn];
bool cmp(Edge x,Edge y){
	return x.w < y.w;
}
int find(int x){
	if(f[x] == x)return x;
	return f[x] = find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,c;
	cin>>n>>m>>c;
	for(int i=1;i<=n + c;i++){
		f[i] = i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	m++;
	for(int i=1;i<=c;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			int wa;
			cin>>wa;
			e[m].u = n + i,e[m].v = j,e[m].w = wa; 
			m++;
		}
	}
	m--;
	sort(e + 1,e + m + 1,cmp);
	for(int i=1;i<=n + c;i++){
		f[i] = i;
	}
	LL ans = 0;
	for(int i=1;i<=m;i++){
		int fx = find(e[i].u),fy = find(e[i].v);
		if(fx != fy){
			ans += 1LL * e[i].w; 
			f[fx] = fy;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 6 0
1 2 5
1 3 2
1 4 1
3 4 2
2 3 10000
2 4 2*/
