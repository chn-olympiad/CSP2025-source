#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int fa[10005];
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
struct Node{
	int u,v,w;
}r[1500005];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		r[i].u=u;r[i].v=v;r[i].w=w;
	}
	for(int i=0;i<k;i++){
		int _,u,w[10001];
		cin>>_;
		for(int i=1;i<=n;i++){
			cin>>w[i];
			if(w[i]==0) u=i;
		}
		for(int i=1;i<=n;i++){
			if(u!=i){
				r[m].u=u;r[m].v=i;r[m].w=w[i];
				m++;
			}
		}
	}
	sort(r,r+m,cmp);
	int ans=0;
	for(int i=0;i<m;i++){
		if(find(r[i].u)!=find(r[i].v)){
			fa[find(r[i].u)]=find(r[i].v);
			ans+=r[i].w;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
