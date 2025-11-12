#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node{
	int u,v,w;
}p[N];
struct edge{
	int c;
	int a[N];
}q[N];
bool f[N];
bool cmp(node x,node y){
	return x.w < y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> p[i].u >> p[i].v >> p[i].w;
	}
	for(int i = 1; i <= k; i++){
		cin >> q[i].c;
		for(int j = 1; j <= n; j++){
			cin >> q[i].a[j]; 
			if(q[i].a[j] == 0){
				f[j] = 1;
			}
		}
	}
	long long s = 0;
	for(int i = 1; i <= n; i++){
		int mi = 100000;
		for(int j = 1; j <= m; j++){
			if(f[i] != 0){
				if(q[j].a[i] < mi){
					mi = q[j].a[i];
				}
				if(p[i].w < mi){
					mi = p[i].w;
				}
			}
		}
		s += mi;
	}
	cout << s;
	return 0;
} 
