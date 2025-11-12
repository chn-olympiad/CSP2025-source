#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long sum=0;
	int u[m]={};
	int v[m]={};
	int w[m]={};
	int ji[k][n]={};
	for(int i = 0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i = 0;i<k;i++){
		for(int a=0;a<n;a++){
			cin>>ji[i][a];
		}
	}
	for(int i = 0;i<m-1;i++){
		for(int j = 0;j<=i;j++){
			if(w[j]<=w[j+1]){
				swap(w[j],w[j+1]);
				swap(u[j],u[j+1]);
				swap(v[j],v[j+1]);
			}
		}
	}
	int sad=n;
	for(int i = 0;i<n;i++){
		if(u[i]==u[i+1]){
			sum+=w[i]+w[i+1];
		}
	}
	for(int i = 0;i<k;i++){
		for(int j = 0;j<n-1;j++){
			if(ji[j][0]<=ji[j][1]){
				swap(ji[j][0],ji[j+1][0]);
			}
		}
	}
	for(int i = 0;i<k;i++){
		if(ji[i][1]==1){
			sum+=ji[i][0];
		}
	}
	cout<<sum;
	
	return 0;
} 

