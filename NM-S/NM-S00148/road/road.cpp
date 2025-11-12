#include<bits/stdc++.h>
using namespace std;
const int M = 1e6 + 1000;
const int N = 1e4 +50;
int n , m , k; 
int node[N];
long long ans;
struct Edge{
	int u , v; 
	long long w;
}edge[M];
bool cmp(Edge a , Edge b){
	return a.w < b.w;
}
void init(){
	for(int i = 1 ; i <= n ; i++){
		node[i] = i;
	}
}
int find(int x){
	return (x == node[x] ? x : node[x] = find(node[x]));
}

void kru(){
	ans = 0;
	init();
	sort(edge+1 , edge+1+m , cmp);
	long long cnt = 0;
	long long idx = 1;
	while(cnt < (n-1)){
		int u = find(edge[idx].u);
		int v = find(edge[idx].v);
		if(u != v){
			node[u] = v;
			ans+=edge[idx].w;
			cnt++;
		}
		idx++;
	}
}

int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 1 ; i <= m ; i++){
		scanf("%d%d%lld" , &edge[i].u , &edge[i].v , &edge[i].w);
	} 
	for(int i = 1 ; i <= k ; i++){
		long long c , c1 , cu , cv;
		long long min1 = 0x3f , min2 = 0x3f;
		scanf("%lld" , &c);
		for(int j = 1 ; j <= n ; j++){
			scanf("%lld" , &c1);
			if(j==1) min1 = c1 , cu = j;
			else{
				if(c1 < min1){
					min2 = min1; cv = cu;
					min1 = c1; cu = j;
				} 
				else if(c1 > min1 && c1 < min2){
					min2 = c1; cv = j;
				}
			}
		}
		edge[++m].u = cu;
		edge[m].v = cv;
		edge[m].w = (min1+min2+c); 
	}
	kru();
	printf("%lld\n" , ans);
	return 0;
}
