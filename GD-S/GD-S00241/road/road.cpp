#include<bits/stdc++.h>
//Ren5Jie4Di4Ling5%
using namespace std;
int n,m,k,c[10005],yichzh[10005];
int parent[10005];

struct Edge{
	int u,v,w,shifouchzh;
}edges[1100005];

bool cmp(Edge a,Edge b){
	return a.w < b.w;
}

//bool cmp1(Edge a,Edge b){
//	if(a.shifouchzh == 1 && b.shifouchzh == 0){
//		return a.w - c[a.u] < b.w;
//	}
//	else if(a.shifouchzh == 0 && b.shifouchzh == 1){
//		return a.w < b.w - c[b.u];
//	}
//	else if(a.shifouchzh == 1 && b.shifouchzh == 1){
//		return a.w - c[a.u] < b.w - c[b.u];
//	}
//	return a.w < b.w;
//}
int find(int x){
	if(parent[x] != x){
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

int kruskal(){
	long long ans = 0;
	int totaledges = 0;
	
	for(int i = 1;i <= n;++i){
		parent[i] = i;
	}
//	for(int i = 0;i < (m + k * (n - 1));++i){
//		cout << edges[i].u << " " << edges[i].v << " " << edges[i].w << " " << edges[i].shifouchzh << " " << endl;
	}
	sort(edges,edges + m,cmp);
	
	
	for(int i = 0;i < m;++i){
		if(totaledges == n - 1){
			break;
		}
		
		int rootu = find(edges[i].u);
		int rootv = find(edges[i].v);
		
		if(rootu != rootv){
			parent[rootu] = rootv;
			//cout << rootu << "hebi" << rootv << endl;
			ans += edges[i].w;
			
			totaledges++;
		}
	}
	
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i = 0;i < m;++i){
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	
	
	long long result = kruskal();
	
	cout << result;
} 
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
