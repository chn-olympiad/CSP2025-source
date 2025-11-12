#include<bits/stdc++.h>
using namespace std;
long long n,m,mn=1e18,k,cnt,c[1000006];
struct hh{
	int u,v,w;
}a[1000006];
bool cmp(hh x,hh y){
	return x.w<y.w;
}
int fa[10006];
int find(int x){
	if(fa[x]!=x)return fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++){
		if(fa[find(a[i].u)]!=fa[find(a[i].v)]){
			cnt+=a[i].w;
			fa[find(a[i].u)]=fa[find(a[i].v)];
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
