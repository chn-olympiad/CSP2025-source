#include<bits/stdc++.h>
using namespace std;
long long a[4][100005],t,n,ma=0,dp[100005],m1=0,m2=0,m3=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			ma=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(ma>=a[i][j]){
					ma=a[i][j];
					dp[i]=j;
				}
			}
		}
		for(int i=1;i<=n/2;i++){
			ma=i;
			for(int j=i+1;j<=n;j++){
				if(a[j][1]>=a[ma][1]){
					ma=j;
				}
			}
			swap(a[ma][1],a[i][1]);
		}
		for(int i=1;i<=n/2;i++){
			cout<<a[i][1];
		}
	}
	return 0;
}

