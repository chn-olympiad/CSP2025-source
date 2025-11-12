#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],sum[505][505],b[5005];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]*2;
	}
	for(int len=3;len<=n;len++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n-len+1;j++){
				sum[i][j]=max(sum[i][j-1],sum[i-1][j])+a[j];
				if(sum[i][j]>b[j]) ans++; 
				cout<<sum[i][j]<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
