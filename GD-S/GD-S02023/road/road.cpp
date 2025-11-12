#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10011],sz[10011],c[11],ans,cnt;
struct e{
	int u,v,w;
	bool operator <(const e x)const{
		return w<x.w;
	}
}a[1100001];
int fd(int x){
	return (fa[x]==x)?x:(fa[x]=fd(fa[x]));
}
void merge(int x,int y){
	x=fd(x);
	y=fd(y);
	if(sz[x]>sz[y])swap(x,y);
	fa[x]=y;
	sz[y]+=sz[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x=m+(i-1)*n+j;
			cin>>a[x].w;
			a[x].u=n+i;
			a[x].v=j;
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		sz[i]=1;
	}
	sort(a+1,a+m+n*k+1);
	for(int i=1;i<=m+n*k;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(fd(u)!=fd(v)){
			merge(u,v);
			ans+=w;
			cnt++;
			if(cnt==n+k-1)break;
		}
	}
	cout<<ans;
}
