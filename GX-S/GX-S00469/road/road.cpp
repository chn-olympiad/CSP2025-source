#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
}a[1000005];
int ci[15][10005],c[15];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[10005];
int find(int x){
	if(fa[x]!=x) return fa[x]=find(x);
	else return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	for(int i=1;i<=m;++i){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++i){
			cin>>ci[i][j];
		}
	}
	if(k==0){
		int cnt=0,ww=0;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;++i){
				if(cnt==n-1){
					cout<<ww;
					return 0;
				} 
				int u1=find(a[i].u),v1=find(a[i].v);
				if(u1!=v1){ 
					ww+=a[i].w;
					fa[u1]=fa[v1];
					cnt++;
					
				}
		}
	}
	return 0;
}
