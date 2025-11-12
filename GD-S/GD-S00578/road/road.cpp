#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int fa[N];
struct node{
	int u,v,w;
}a[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	int ans=0;
	for(int i=1;i<=n; i++)fa[i]=i;
	for(int i=1; i<=m; i++){
		int fa1=find(a[i].u),fa2=find(a[i].v);
	//	cout<<fa1<<" "<<fa2<<endl;
		if(fa1!=fa2){
			fa[fa2]=fa1;
			cout<<a[i].w<<endl;
			ans+=a[i].w;
		}
	}
	cout<<ans;
}
