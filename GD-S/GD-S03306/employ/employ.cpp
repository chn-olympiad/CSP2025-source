#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<ostream>
#include<bits/stdc++.h>
#define MOD 998244353 
using namespace std; 
int n,m;
string a;
int care[510];
int dp[510][510];
int jc(int number){
	if(number<2){
		return 0;
	}
	return number*jc(number-1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>care[i];
		if(care[i]==1){
			t++;
		}
	}
	if(t==n){
		long long cc=(jc(n))%MOD/((jc(m)%MOD)*(jc(m-n))%MOD);
		cout<<(cc%MOD);
	
		fclose(stdin);
	fclose(stdout); 
	
	return 0;
}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i][j-1],dp[i][j-1]+care[m]);
		}
	}
	cout<<dp[m][n-1];
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}







































