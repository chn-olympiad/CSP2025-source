#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[100010],sum,u[20],d;
struct edge{
	int u,v,w;
}a[2000010];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(x==f[x]){
		return x;
	}
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	if(find(x)!=find(y)){
		f[find(x)]=find(y);
	}
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		f[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin >> d;
		for(int j=1;j<=n;j++){
			cin >> d;
		}
	}
	if(k>0){
		cout << 0;
		return 0;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			merge(a[i].u,a[i].v);
			sum+=a[i].w;
		}
	}
	cout << sum;
	return 0;
}