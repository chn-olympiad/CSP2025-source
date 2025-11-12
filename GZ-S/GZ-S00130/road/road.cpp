//GZ-S00130 贵阳市第一中学  孙乙洋
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,ans,fa[N];
struct node{
	int u,v,w;
}a[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v;
		if(find(u)==find(v)) continue;
		fa[find(u)]=find(v),ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}
