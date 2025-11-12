#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[10010],u[10010],v[10010],c[15],res;
int a[15][10010],x,y;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
	cin>>c[i]>>a[i][j];
}
}
if(k==0){
	for(int i=1;i<=m;i++){
		res=res+w[i];
	}
}else{
for(int i=1;i<=k;i++){
	for(int j=1;j<=n;j++){
	x+=c[i];
	y+=a[i][j];
}
}
if(x==0&&y==0){
		res=0;
	}else{
	res+=w[i]+c[i]-a[i][j];
	}
}
cout<<res;
	return 0;
}
