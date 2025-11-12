#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	int sum[n][n],max1[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum[i][j]=0;
			max1[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<1;i++){
		for(int j=0;j<n;j++){
			sum[i][j]=a[j];
			max1[i][j]=a[j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			max1[i][j]=max1[i-1][j+1];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			if(j+i<n){ 
				sum[i][j]=sum[i-1][j]+sum[0][j+i];
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(sum[i][j]>2*max1[i][j] && sum[i][j]!=0 && max1[i][j]!=0){
				ans++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int k=1;k<n;k++){
			for(int j=i+2;j<n;j++){
				if(sum[k][j]+sum[0][i]>2*max1[k][j] && sum[k][j]!=0 && max1[k][j]!=0){
					ans++;
				}
			}
		}
	}		
	cout<<ans%998<<ans%224<<ans%353;
	return 0;
}