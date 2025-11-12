#include<bits/stdc++.h>
using namespace std;
struct node{
	int u, v;
	long long w;
}a[1000006];
int n, m, k;
int top = m;
int fa[20005];
bool cmp(node z, node j){
	return z.w < j.w;
}
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
void kruskal(){
	long long ans = 0;
	for(int i = 1; i <= top; i++){
		int xx = a[i].u, yy = a[i].v;
		if(find(xx) != find(yy)){
			fa[find(xx)] = find(yy);
			ans += a[i].w;
		} 
	}
	cout << ans;
}
int main(){
	freopen("road.in","r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i<=n+k; i++) fa[i]=i;
	for(int i = 1; i<= m; i++){
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	}
	top=m;
	for(int i = 1; i <= k; i++){
		int x;
		scanf("%d",&x); 
		for(int j = 1; j <= n; j++){
			long long ww;
			scanf("%lld", &ww);
			if(ww == 0){
				fa[i+n]=j;
			}else {
				a[++top].u = i+n;
				a[top].v = j;
				a[top].w = ww;
			}
		}
	}
	sort(a+1,a+1+top, cmp);
	kruskal();
	return 0;
} 
