#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[1000001][3],best[6],sum[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int l=1;l<=t;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		sum[1]=a[1][1]+a[2][2];
		sum[2]=a[1][1]+a[2][3];
		sum[3]=a[1][2]+a[2][1];
		sum[4]=a[1][2]+a[2][3];
		sum[5]=a[1][3]+a[2][1];
		sum[6]=a[1][3]+a[2][2];	
		sort(sum,sum+7);
		best[l]=sum[6];
	}
	for(int l=1;l<=t;l++){
	cout<<best[l]<<endl;	
	}
return 0;
}
