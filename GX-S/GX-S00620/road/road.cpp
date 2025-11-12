#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10001],ans;
struct B{
	int a,b,c;
}cb[1000001];
bool cmp(B a,B b){
	return a.c<b.c;
}
int find(int a){
	return fa[a]==a?a:fa[a]=find(fa[a]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		cin>>cb[i].a>>cb[i].b>>cb[i].c;
	}
	sort(cb+1,cb+m+1,cmp);
	for(int i=1;i<=m;++i){
		int u=cb[i].a,v=cb[i].b,w=cb[i].c;
		if(find(u)==find(v)) continue;
		fa[find(u)]=find(v);
		ans+=w;
	}
	cout<<ans;
	return 0;
}
