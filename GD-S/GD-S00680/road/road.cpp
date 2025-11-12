#include<bits/stdc++.h>
using namespace std;
struct rd{
	int u,v,w;
}a[1000010];
bool cmp(rd lef,rd rig){
	return lef.w<rig.w;
}
int n,m,k,f[10010],c[15],lian[15][10010],lianed;
long long ans=0;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void uni(int x,int y){
	int lef=find(x),rig=find(y);
	if(lef!=rig)f[rig]=lef;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>lian[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(lianed>=n-1){
			break;
		}
		if(find(a[i].u)!=find(a[i].v)){
			uni(a[i].u,a[i].v);
			ans+=a[i].w;
			lianed++;
		}
	}
	cout<<ans;
	return 0;
} 
