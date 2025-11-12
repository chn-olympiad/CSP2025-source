#include<bits/stdc++.h>
using namespace std;
int t,n;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int m=n/2;
		int a[n][4];
		int dp[n][8];
		int b[4];
		memset(b,0,sizeof b);
		for(int i=0;i<n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dp[0][1]=a[0][1];
		dp[0][2]=a[0][2];
		dp[0][3]=a[0][3];
		
	
		for(int i=1;i<n;i++){
			bool tt=true;
			for(int j=1;j<=3;j++){
				int m1=1;
				int m11=1;
				int m2=1;
				int m22=1;
				int m3=INT_MAX;
				int m33=1;
				for(int k=1;k<=3;k++){
					if(dp[i-1][k]>dp[i-1][m11]){
						m1=dp[i-1][k];
						m11=k;
					}
					if(dp[i-1][k]<dp[i-1][m33]){
						m3=dp[i-1][k];
						m33=k;
					}
				}
				for(int k=1;k<=3;k++){
					if(k!=m11 and k!=m33){
						m2=dp[i-1][k];
						m22=k;
					}
				}
				
				if((m11!=j and b[m11]<m) or (m11==j and b[m11]+1<=m)){
					dp[i][j]=m1+a[i][j];
					
				}else if(m11==j and b[m11]+1>m){
					dp[i][j]=m2+a[i][j];
					
				}
				b[m11]++;
			}
		}
		
		cout<<max({dp[n-1][1],dp[n-1][2],dp[n-1][3]})<<endl;
	}
	return 0;
}
