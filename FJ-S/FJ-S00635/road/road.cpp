#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int w[m],u[m],v[m],a[k],w1[m],w2[m],w3[m],a1[k];
	for(int i=0;i<=m;i++){
		cin>>w[i];//修路费 
		w1[1]+=w[i];
	}
	for(int i=0;i<=m;i++){
		cin>>u[i];//u路
		w2[1]+=u[i]*w[i]; 
	}
	for(int i=0;i<=m;i++){
		cin>>v[i];//v路
		w3[1]+=v[i]*w[i];
		 
	}
	if(k>0){
		for(int i=0;i<=k;i++){
			cin>>a[i];//城市化费用
			a1[i]+=a[i]; 
		}
	}else{
		
	}
	
	cout<<w1[1]+w2[1]+w3[1]+a1[1];
	return 0;
}
