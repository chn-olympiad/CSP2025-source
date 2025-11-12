#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long ans;
struct Node{
	long long u,v,w;
}a[1110000];
int dw[11][100001];
long long kw[11];
bool kvis[11];
long long f[111000];
int find(long long x){
	if(x == f[x]){
		return x;
	}
	return f[x] = find(f[x]);
}
void uni(long long x,long long q){
	if(x == f[x]){
		f[x] = q;
		return;
	}
	uni(f[x],q);
	f[x] = q;
}
bool cmp(Node x,Node y){
	return x.w < y.w;
}
void kul(){
	long long cnt = 0;
	for(int i=1;i<=m;i++){
		long long u = a[i].u,v = a[i].v,w = a[i].w;
		if(find(u) != find(v)){
			ans += w;
			uni(u,f[v]);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(kw,0,sizeof(kw));
	memset(kvis,0,sizeof(kvis));
	for(int i=1;i<=m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i=1;i<=n;i++){
		f[i] = i;
	}
	for(int i=1;i<=k;i++){
		cin >> kw[i];
		for(int j=1;j<=n;j++){
			cin >> dw[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	kul();
	cout << ans ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
