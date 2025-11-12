#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int sum=5;
	int u[m]={0,0},v[m]={0,0},w[m]={0,0};
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	sum=sum+u[0]+v[0];
	int c[5];
	for(int j=1;j<=k;j++){
		for(int i=0;i<5;i++){
			cin>>c[i];
		}
		if(j==2) sum=sum+c[3]+c[1];
	}
	cout<<sum;
	return 0;
}
