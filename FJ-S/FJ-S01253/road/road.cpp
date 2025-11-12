#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m,k;
int fa[maxn];
struct node{
	int u,v,w;
}s[maxn];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void craft(int u,int v){
	u=find(u),v=find(v);
	if(u!=v) fa[u]=v;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	sort(s+1,s+1+m,cmp);
	int r=0,ans=0;
	for(int i=1;i<=m;i++){
		if(r==n-1) break;
		if(find(s[i].u)!=find(s[i].v)){
			craft(s[i].u,s[i].v);
			ans+=s[i].w;
			r++;
		}
	}
	cout<<ans;
	return 0;
}
