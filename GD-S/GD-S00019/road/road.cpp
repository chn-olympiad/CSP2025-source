#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,ans;
struct node{
	int u,v,w;
}a[M];
int fa[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]!=x) return find(fa[x]);
	return x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int U,V;
	for(int i=1;i<=m;i++){
		cin>>U>>V>>a[i].w;
		a[i].u=U,a[i].v=V;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)) fa[a[i].u]=a[i].v,fa[a[i].v]=a[i].u,ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}


