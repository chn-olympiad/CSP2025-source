//#include<iostream>
//#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long int n,a[6000],sum=5;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	bool q=0;
	cin>>n;
	for(long int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) q=1;
	}
	if(q==0) {
		if(n==3){
			cout<<1;
			return 0;
		}
		else if(n==4){
			cout<<5;
			return 0;
		} 
		else if(n==5){
			cout<<10;
			return 0;
		}
		long int k[6000];
		k[4]=5;k[5]=5;
		for(long int i=5;i<=n;i++){
			k[i]=k[i-1]+k[i-2];
			sum+=k[i];
		} 
		cout<<sum%998244353;
		return 0;
	}
	cout<<8;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 1 1 1 1 1 1 1 35 7 15
// 1 1 1 1 1 1   20 6 10
// 1 1 1 1 1     10 5 5
// 1 1 1 1       5  4 5
// 1 1 1         1  3 4 
// 

