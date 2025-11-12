#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct ct{
	int v;//向 
	int w;//花费 
};
struct ct2 {
	int u;
	int v;//向
	int w;//花费
};
int n,m,k;
int fa[N];
int city[20];
int cit[20][N];
vector<ct> e[N];
vector<ct2> e2;
ct lct(int x,int y){//LONT_CITY
	int mim=INT_MAX;
	int d;
	for(int i=1;i<=k;i++){
		if(cit[i][x]+cit[i][y]+city[i]<=mim){
			mim=min(mim,cit[i][x]+cit[i][y]+city[i]);
			d=i;
		}
	}
	ct h={mim,d};
	return h;
}
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void hb(int x,int y) {
	fa[find(y)]=find(x);
}
bool cmp(ct2 l,ct2 r) {
	return l.w<r.w;
}
int dfs(int x,int y,int step){
	if(step>=n){
		return y;
	}
	
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k==0) {
		for(int i=1; i<=n; i++) {
			fa[i]=i;
		}
		for(int i=1; i<=m; i++) {
			int a1,a2,a3;
			scanf("%d%d%d",&a1,&a2,&a3);
			e2.push_back({a2,a1,a3});
		}
		sort(e2.begin(),e2.end(),cmp);
		int sum=0;
		for(ct2 eu:e2) {
			if(find(eu.u)!=find(eu.v)) {
				hb(eu.u,eu.v);
				sum+=eu.w;
			}
		}
		printf("%d",sum);
	}

	return 0;
}
/*/
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

/*/
