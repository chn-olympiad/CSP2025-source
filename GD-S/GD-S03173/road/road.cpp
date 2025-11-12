#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,x,y,z,sk,zd;
long long a[11][222222],f[222222],r[1111][1111];
struct node{
	long long u,v,w;
}cc[2222222];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>cc[i].u>>cc[i].v>>cc[i].w;
	}
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=k;i++){
		cin>>sk;
		a[i][0]=sk;
		for(int u=1;u<=n;u++){
			cin>>a[i][u];
			if(sk==0&&a[i][u]==0) f[y]=x;
			if(sk==0){
				r[u][i]=a[i][u];
				r[i][u]=a[i][u];
			}
		}
	}
	sort(cc+1,cc+1+m,cmp);
	if(k==0){
		for(int i=1;i<=m;i++){
			x=cc[i].u;
			y=cc[i].v;
			z=cc[i].w;
			if(find(x)!=find(y)){
				f[find(y)]=find(x);
				ans+=z;
			}
		}
		return cout<<ans,0;		
	}
	for(int i=1;i<=m;i++){
		x=cc[i].u;
		y=cc[i].v;
		z=cc[i].w;
		zd=1e18;
		if(find(x)!=find(y)){
			for(int u=1;u<=k;u++){
				zd=min(zd,r[x][u]+r[y][u]);
			}
			f[find(y)]=find(x);
			if(zd<z) ans+=zd;
			else ans+=z;
		}
	}
	cout<<ans;
	return 0;
}
