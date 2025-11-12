#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,w[15][10005],fa[10005],h[15],km;
ll s;
struct ab{
	int u,v,w;
}a[10000005];
bool cmp(ab x,ab y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&h[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&w[i][j]);
			if(w[i][j]!=0) flag=1;
		}
		if(h[i]!=0) flag=1;
	}
	if(!flag) return cout<<0,0;
	for(int ii=1;ii<=k;ii++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				a[++m].w=w[ii][j]+h[ii]+w[ii][i];
				a[m].u=i;
				a[m].v=j;
			}
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			s+=a[i].w;
			fa[a[i].u]=fa[a[i].v];
			km++;
		}
		if(km==n-1) break;
	}
	cout<<s;
}
