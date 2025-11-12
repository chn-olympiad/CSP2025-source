#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

const int MAXN = 1e4+5;

struct edge{
	int fr;
	int to;
	int we;
};
vector<edge>graph[MAXN];
struct gz{
	int ned;
	int to_a[30];
}cities[15];
int n,m,k;

int fa[MAXN];
int find(int a){
	int b = a;
	while(a!=fa[a]){
		a = fa[a];
	}
	fa[b] = a;
}

inline bool count_num(){
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(fa[i] = i)cnt++;
	}
	if(cnt==1)return 1;
	return 0;
}
vector<edge>edge_set;
int ex;
bool cmp(edge a,edge b){
	return a.we<b.we;
}

int prim(int ns){
	int ans = 0;
	edge_set.clear();
	for(int i = 1;i<=n;i++){
		fa[i] = i;
	}
	for(int i = 1;i<=n;i++){
		for(auto xs:graph[i]){
			edge_set.push_back(xs);
		}
		sort(edge_set.begin(),edge_set.end(),cmp);
		while(!count_num()){
			edge fi = *edge_set.begin();
			if(find(fi.fr)==find(fi.to)){
				edge_set.erase(edge_set.begin());
			}
			else{
				fa[fi.to] = fa[fi.fr];
				if(fi.to==ns){
					for(int j = 1;j<=n;j++){
						edge_set.push_back({ns,cities[ns].to_a[j]});
					}
				}
				ans += fi.we;
				for(auto xs:graph[fi.to]){
					edge_set.push_back(xs);
				}
				sort(edge_set.begin(),edge_set.end(),cmp);
			}
		}
	}
	return ans;
}
int max_ans = 0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int f,t,w;
		cin>>f>>t>>w;
		graph[f].push_back({f,t,w});
		graph[t].push_back({t,f,w});
	}
	for(int i = 1;i<=k;i++){
		cin>>cities[i].ned;
		for(int j = 1;j<=n;j++){
			cin>>cities[i].to_a[j];
		}
	}
	for(int i = 1;i<=k;i++){
		int n_ans = cities[i].ned;
		max_ans = max(max_ans,prim(i));
	}
	cout<<max_ans;
	return 0;
} 
