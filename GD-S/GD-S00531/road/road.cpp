#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a[1005][1005],b[1005][1005],sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	int xt=a[1][1];
	for(int i=1;i<=n/2;i++){
		for(int j=2;j<=2;j++){
			if(xt==a[i][j]){
				xt=0;
			}
		}
	}
	if(xt!=0){
		for(int i=1;i<=n/2;i++){
			for(int j=n-1;j<=3;j++){
				sum+=a[i][j];
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
