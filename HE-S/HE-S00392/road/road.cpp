#include<bits/stdc++.h>
using namespace std;

int u[10001],v[10001],w[10000001],c[10001][10001],bj[10000001];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		for(int k=1;k<=n;k++){
			cin>>c[j][k];
		}
	}
	
	int minlu=1000001,bjqian,minqian=0,dabiaoji=0;
	
	for(int i=1;i<=m;i++){
			if(minlu>w[i]){
				minlu=w[i];
				bjqian=i;
			}
		}
	minqian+=minlu;
	bj[u[bjqian]]=-1;
	bj[v[bjqian]]=-1;
	
	while(1){
		minlu=1000001;
		dabiaoji=0;
		for(int i=1;i<=n;i++){
			if(bj[i]==0){
				dabiaoji=1;
			}
		}
		if(dabiaoji==0){
			break;
		}
		for(int i=1;i<=m;i++){
			if(minlu>w[i] && (bj[v[i]]==0||bj[u[i]]==0) && (bj[v[i]]!=0||bj[u[i]]!=0)){
				minlu=w[i];
				bjqian=i;
			}
		}
		minqian+=minlu;
		bj[u[bjqian]]=-1;
		bj[v[bjqian]]=-1;
	}
	cout<<minqian;
	
	fclose(stdin);
	fclose(stdout);
}
