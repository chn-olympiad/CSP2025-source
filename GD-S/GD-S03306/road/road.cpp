#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<ostream>
#include<bits/stdc++.h>
using namespace std; 
int city,road,vil;
int w[10005];
int u[1];
int v[1];
int vill[11];
int vs[1][1];
int dp[10005][10005]={1};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>city>>road>>vil;
	for(int i=1;i<=road;i++){
		cin>>u[1]>>v[1]>>w[i];
	}
	
	for(int i=1;i<=vil;i++){
		cin>>vill[i];
		for(int j=1;j<=city;j++){
			cin>>vs[1][1];
		}
	}
	for(int i=1;i<=city;i++){
		for(int j=1;j<=road;j++){
			dp[i][j]=max(dp[i][j-1],dp[i][j-1]+w[j]);
			
		}
	}
	cout<<dp[city][road];
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}







































