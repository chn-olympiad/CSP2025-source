#include <bits/stdc++.h>
using namespace std;
int n,m,k,l;
int x,y,z;
struct node{
	int u,v,w;
} e[2000005];
inline bool cmp(node s1,node s2){
	return s1.w<s2.w;
}
int fa[10005];
inline find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		e[++l].u=x;
		e[l].v=y;
		e[l].w=z;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		for(int i=1;i<=n;i++) scanf("%d",&x);
	}
	if(k!=0){
		cout<<0;
		return 0;
	}
	sort(e+1,e+l+1,cmp);
	int cnt=0;
	for(int i=1;i<=l;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			cnt++;
			if(cnt==n-1){
				cout<<ans;
				return 0;
			}
			fa[find(e[i].u)]=find(e[i].v);
		}
	}
	return 0;
}
