#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans,c[20],fa[10010],uuse[20],xc[20][10010];
struct no{
	int u,v,w;
}a[10000010];
bool fl=0,oop;
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(no aa,no bb){
	return aa.w<bb.w;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) fl=0;
		for(int j=1;j<=n;j++){
			cin>>xc[i][j];
			a[++m]={n+i,j,xc[i][j]};
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy){
			if(fx>n){
				if(uuse[fx-n]==0) uuse[fx-n]=1,ans+=c[fx-n];
			} 
			ans+=a[i].w,fa[fy]=fx;
		}
	}
	cout<<ans;
	return 0;
}
/*
16:00最小生成树???
16:24 got 16pts
17:57 实在不知道该说什么了,恶心

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

死了 
*/
