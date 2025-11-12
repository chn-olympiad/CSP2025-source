#include<iostream>
using namespace std;
int ans,s[10002];
struct c{
	int co,a[10002];
}c0[10002];
struct r{
	int u,v,w;
}r0[1000002];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r0[i].u>>r0[i].v>>r0[i].w;
		
		if((s[r0[i].u]=0)||(s[r0[i].v]=0)){
			ans+=r0[i].w;
		}
		s[r0[i].u]=1;s[r0[i].v]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c0[i].co;
		for(int j=1;j<=n;j++){
			cin>>c0[i].a[j];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
