#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int zj=0;
	int n,m,k;
	cin>>n>>m>>k;
	int u[m+1],v[m+1],w[m+1];
	int c[k+1],a[k+1][n+1];
	int minw=9999,minwi=0,minc=9999,minci=0;
	int mina[k+1]={9999},minaj[k+1]={0};
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		if(w[i]<minw){
		minw=w[i];
		minwi=i;
		}
	}
	for(int i=1;i<=k;i++){
		if(c[i]<minc){
		minc=c[i];
		minci=i;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]<mina[i]){
			mina[i]=a[i][j];
			minaj[i]=j;
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(minci==i&&mina[i]<minw&&minc<minw) zj+=minc+mina[i]+minw;
		else if(minci==i&&minc<minw) zj+=minc+mina[i]+minw;
		else zj+=minw;
	}
	cout<<zj;
	return 0;
}
