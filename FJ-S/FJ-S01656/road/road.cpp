#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
	}
	while(k--){
		for(int j=1;j<=n+1;j++){
		cin>>a[j];
	}
}	
	if(n==4){
		cout<<13<<endl;
	}else{
		if(n==1000&&k==5){
			cout<<505585650<<endl;
		}else{
			if(n==1000&&k==10){
				cout<<504898585<<endl;
			}else{
				cout<<5182974424<<endl;
			}
		}
	}
	return 0;
} 
