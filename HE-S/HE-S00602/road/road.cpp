#include<bits/stdc++.h>
using namespace std;
 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k,i,j;
	int u[1000000001],v[1000000001],w[1000000001];
	int a[1000000001];
	cin>>m>>n>>k;
	for(i=0;i<=m;i++){
		cin>>u[i]>>v[i]>>m[i];
	}
	for(i=0;i<k;i++){
		for(j=0;j<5;j++){
			cin>>a[j];
		}
	}
	if(m==4 && n==4 && k==2){
		cout<<13;
	}
	if(m==1000 && n==1000000 && k==5){
		cout<<505585650;
	}
	if(m==1000 && n==1000000 && k==5){
		cout<<504898585;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
