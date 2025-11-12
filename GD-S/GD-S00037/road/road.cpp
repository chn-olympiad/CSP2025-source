#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct box{
	int u,v,w;
}a[1000004];
int rt[10004];
long long ans;
bool cmp(box a,box b){
	return a.w<b.w;
}
int find(int now){
	if(rt[now]==now)return now;
	return find(rt[now]);
}
void build(){
	for(int i=1;i<=m;++i){
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu==fv)continue;
		rt[fu]=fv;
		ans+=a[i].w;
	}
}
int main(){
	freopen("road.in ","r",stdin);
	freopen("road.in ","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n;++i){
		rt[i]=i;
	}
	sort(a+1,a+m+1,cmp);
	build();
	cout<<ans;
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
