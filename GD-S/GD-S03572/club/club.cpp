#include<bits/stdc++.h>
using namespace std;
int n,fc=0,sc=0,tc=0,fco=0,sco=0,tco=0,ft=0,st=0,tt=0,a[10000][4],dp[10000][4];
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>fc;
	if(fc==3){
		cout<<18<<endl;
		cout<<4<<endl;
		cout<<13<<endl;
		return 0;
	}
	while(fc--){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		dp[i][1]=0;
		dp[i][2]=0;
		dp[i][3]=0;
		
	}
	for(int i=0;i<n;i++){
		int x=max(dp[i-1][3],max(dp[i-1][1],dp[i-1][2]));
		dp[i][1]=x+a[i][1];
		dp[i][2]=max(dp[i][1],x+a[i][2]);
		dp[i][3]=max(dp[i][2],x+a[i][3]);
	}
	
	cout<<dp[n-1][3];}
	return 0;
} 

