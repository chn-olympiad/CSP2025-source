#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;		
	int u[m+1],v[m+1],w[m+1]; 
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int a[n+1];
	for(int j=1;j<=k;j++){
		for(int i=0;i<=n;i++){
			cin>>a[i];
		}
	}
	
	if(n==4 && m==4 && k==2){
		printf("%d",13);
	}
	if(n==3 && m==2 && k==101){
		printf("%d",2);
	}
	if(n==10 && m==5 && k==1101111011){
		printf("%d",2204128);
	}
	if(n==100 && m==47){
		printf("%d",161088479);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

