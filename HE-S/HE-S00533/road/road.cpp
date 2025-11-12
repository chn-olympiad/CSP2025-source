#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int ans;
vector<int>tree1[114514];
struct TREE{
	int u,v,w;
}tree[114514];
bool cmp(TREE x,TREE y){
	return x.w<y.w;
}
int find(int x){
	if(tree1[x]<0)return x;
	return find(tree1[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>tree[i].u>>tree[i].v>>tree[i].w;
	}
	sort(tree+1,tree+m+1,cmp);
	memset(tree1,-1,sizeof(tree1))
	for(int i=2;i<=n;i++){
		int x=find(tree[i].u),int y=find(tree[i].v);
		if(x!=y)){
			tree1[tree[i].u]=y;
			tree1[tree[i].v]=x;
			ans+=tree[i].w;
		}
	}
	cout<<ans;
	return 0;
}
