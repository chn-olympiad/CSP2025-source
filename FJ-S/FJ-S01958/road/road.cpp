#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}b[1000005];
struct node1{
	int w1,id;
}a[1000005];
/*bool cmp(node x,node y){
	return x.w<y.w;
}
bool cmp1(node1 x1,node1 y1){
	return x1.w1<y1.w1;
}*/
int n,m,k,c[1000005],minn; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	//sort(b+1,b+n+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i].w1;
			a[i].id=i;
		}
	}
	//sort(a+1,a+n+1,cmp);
	if(k==0){
		for(int i=1;i<=n;i++){
			minn+=b[i].w;
		}
	}
	cout<<minn;
	return 0;
} 
