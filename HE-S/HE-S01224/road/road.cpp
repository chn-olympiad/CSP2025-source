#include <bits/stdc++.h>
using namespace std;
int n,m,k,minn=2e9,ans;
struct price{
	int u,v,w;
	bool vis;
}c[1000010];
struct country{
	int c1,c2;
	bool vis;
}c1[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>c[i].u>>c[i].v>>c[i].w;
	for(int i=1;i<=k;i++) cin>>c1[i].c1>>c1[i].c2;
	for(int i=1;i<=m;i++) 
		for(int j=1;j<=m;j++) 
			if(c[i].vis==0&&c[i].w<minn){
				minn=c[i].w;
				c[i].vis=1;
			}
		ans+=minn;
	minn=2e9;
	for(int i=1;i<=k;i++){
		if(c1[i].vis==0&&c1[i].c1+c1[i].c2<minn) minn=c1[i].c1+c1[i].c2;
		ans+=minn;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
