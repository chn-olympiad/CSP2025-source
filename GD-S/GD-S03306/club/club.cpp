#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<ostream>
#include<bits/stdc++.h>
using namespace std; 
int n[6],t;
int a[6][100001][3];
int dp[100001][3];
int max1(int a1,int a2,int a3){
		int big=0;
		big=max(big,a1);
		big=max(big,a2);
		big=max(big,a3);
		return big;
}
int dp1(int club,int member,int times){
	int ans=0;
	if(member>n[times]){
		return 1;
	}
	if(club>3){
		return 0;
	}
	for(int i=1;i<=club;i++){
		for(int j=member;j<=n[times];j++){
			//dp[i][j]=max(dp[i][j-1],dp[i][j-1]+a[i][j]);
			ans+=max1(dp1(i,j,times),dp1(i+1,j,times),dp1(i+2,j,times));
		}
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			for(int k=1;k<=3;k++){
				cin>>a[i][j][3];
			}
		}
	}
	
		for(int j=1;j<=n[1];j++){
			dp[j][j]=1;
		}
	for(int u=1;u<=t;u++){
	
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n[u];j++){
			dp[j][i]=max1(dp[j-1][1]+a[u][j][1],dp[j-1][2]+a[u][j][2],dp[j-1][3]+a[u][j][3]);
		}
	}
	cout<<dp[n[u]][3];
}
	
	fclose(stdin);
	fclose(stdout); 
	
	return 0;
}







































