#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int u,v,w;
} a[1000005];
int fa[10005];
bool cmp(road x,road y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x||fa[x]==0) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	  cin>>a[i].u>>a[i].v>>a[i].w;
	int ans=0;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)
	  fa[i]=i;
	for(int i=1;i<=m;i++){
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu!=fv){
			ans+=a[i].w;
			fa[fu]=fv;
			n--;
			if(n==1){
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}

