#include<iostream>
#include<algorithm>
using namespace std;

typedef long long lld;

struct Edge{
	int u,v,id;
	lld w;
}E[4000100];
struct Node{
	lld x,a[10100];
}a[20];
int f[10100];

int find(int x){
	return f[x]==x ? x : f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)] = find(y);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,c=0;
	lld w,s=0;
	cin>>n>>m>>k;
	for(int i = 1; i <= n; i++){
		f[i] = i;
	}
	for(int i = 1; i <= m; i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
		E[i].id = 0;
	}
	for(int i = 1; i <= k; i++){
		cin>>a[i].x;
		for(int j = 1; j <= n; j++){
			cin>>a[i].a[j];
		}
		for(int j = 1; j <= n; j++){
			for(int _k = 1; _k < j; _k++){
				E[++m] = {j,_k,i,a[i].a[j]+a[i].a[_k]+a[i].x};
			}
		}
	}
	sort(E+1,E+m+1,[](Edge a,Edge b){
		return a.w < b.w;
	});
	for(int i = 1; i <= m; i++){
		u = E[i].u;v = E[i].v;w = E[i].w;
		if(find(u) == find(v)){
			continue;
		}
		merge(u,v);
		s += w;
		if(f[E[i].id+n]){
			s -= a[E[i].id].x;
		}else{
			f[E[i].id+n] = 1;
		}
		if(++c == n-1){
			break;
		}
	}
	cout<<s;
	return 0;
}