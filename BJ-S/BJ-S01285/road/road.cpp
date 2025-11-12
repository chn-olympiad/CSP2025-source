#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,fa[10010],c[15],a[15][10010];
ll ans;
struct node{
	int u,v;
	ll sum;
}ed[1000010];
int fd(int a){
	if(fa[a]==a) return a;
	return fd(fa[a]);
}
bool cmp(node a,node b){
	return a.sum<b.sum;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i) {
		cin>>ed[i].u>>ed[i].v>>ed[i].sum;
	}
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	int cnt=m;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			for(int k=j+1;k<=n;++k){
				if(k!=j){
					cnt+=1;
					ed[cnt].u=j;
					ed[cnt].v=k;
					ed[cnt].sum=a[i][j]+a[i][k];
				}
			}
		}
	}
	sort(ed+1,ed+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		if(fd(ed[i].u)!=fd(ed[i].v)){
			fa[fd(ed[i].u)]=fd(ed[i].v);
			ans+=ed[i].sum;
		}
	}
	cout<<ans;
	return 0;
}

