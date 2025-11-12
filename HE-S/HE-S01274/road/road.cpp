#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10,M = 1e4+10;
struct node{
	int u,v,w;
}e[N];
int n,m,k;
int p[20],a[M],fa[M];
bool cmp(node q,node ww){
	return q.w<ww.w;
}
int getfa(int x){
	if(fa[x]==x){
		return x;
	}
	return getfa(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i = 1;i<=n;i++){
		fa[i] = i;
	}
	sort(e+1,e+m+1,cmp);
	for(int i = 1;i<=k;i++){
		cin>>p[i];
		for(int j = 1;j<=n;j++){
			cin>>a[j];
		}
	}
	int o = n-1,ans = 0;
	for(int i = 1;i<=m;i++){
		if(o<=0){
			break;
		}
		int x = getfa(e[i].u);
		int y = getfa(e[i].v);
		if(x!=y){
			fa[x] = y;
			o--;
			ans+=e[i].w;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
