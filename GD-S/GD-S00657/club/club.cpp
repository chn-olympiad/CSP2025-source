#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t>>n;
	int a[n][3],b[10000000],sum[3]={1},c[n+1][4];
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			c[i+1][j+1]==a[i][j];
		}
	}
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(sum[0]<=n/2&&sum[1]<=n/2&&sum[2]<=n/2){
				if(j==1)
				{
				c[i][j]=max(c[i][j]+c[i-1][j],c[i][j]+c[i-1][j+1],c[i][j]+c[i-1][j+2]);
				sum[0]++;}if(j==2)
				{
				c[i][j]=max(c[i][j]+c[i-1][j],c[i][j]+c[i-1][j+1],c[i][j]+c[i-1][j-1]);
				sum[1]++;}
				if(j==3)
				{
				c[i][j]=max(c[i][j]+c[i-1][j],c[i][j]+c[i-1][j-1],c[i][j]+c[i-1][j-2]);
				sum[2]++;}
				
			
				
			}
		}
	}
}
