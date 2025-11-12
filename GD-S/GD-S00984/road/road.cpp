#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	long long a[100][100];
	long long sum=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	long long b[100][100];
	for(int i=1;i<=k;i++){
		cin>>b[i][1];
		for(int j=2;j<=n;j++){
			cin>>b[i][j]; 
		}
	}
	for(int i=1;i<=n-1;i++){
			long long min=pow(10,10);
		for(int j=1;j<=n;j++){
		
			
		long long  min2=pow(10,10);
		int p1=0;
			for(int z=1;z<=m;z++){
				if(a[z][1]==i&&a[z][2]==j){
					if(min2>a[z][3]){
						min2=a[z][3];
						p1=z;
					}
				}
			}
	
			long long min1=pow(10,10);
			int p2=0;
		for(int x=1;x<=k;x++){
			
			if(b[x][i+1]+b[x][j+1]+b[x][1]<min1){
				min1=b[x][i+1]+b[x][j+1]+b[x][1];
				p2=x;
			}
	}
	if(min1<=min2){
		
			min=min1;
			b[p2][i+1]=0;
			b[p2][j+1]=0;
			b[p2][1]=0;
		
	}
	if(min1>min2){
	
			min=min2;
			a[p1][3]=0;
		
	
	}

	sum+=min;

}}
cout<<sum;
return 0;}
