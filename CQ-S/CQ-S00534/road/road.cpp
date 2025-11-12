#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[100005],ans;
struct node{
	int u,v,w;
}a[1000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k!=0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu!=fv){
			fa[fv]=fu;
			ans+=a[i].w;
		}
	}
	cout<<ans;
	return 0;
}
