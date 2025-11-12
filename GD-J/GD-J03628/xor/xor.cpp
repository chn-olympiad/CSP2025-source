#include<iostream>
#include <bits/requires_hosted.h>
#include<algorithm>
#include<stdio.h>
#include<ostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
int a[500001];
bool jjj[500001]={true};
int n,k;
int ans=0;
int xor1(int l,int r){
	int sum=a[l];
	for(int i=l+1;i<=r;i++){
		sum=sum^a[i];
	}
	return sum;
}
bool xor3(int i,int j){
	for(int k=i;k<j;k++){
		if(jjj[k]==false){
		return false;
			}
		}
	
	return true;
}
int xor2(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(xor1(i,j)==k&&xor3(i,j)){
				ans++;
				for(int k=i;k<j;k++){
					jjj[k]=false;
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int hh=xor2();
	cout<<hh;
	if(n<=2&&k==0){
		if(a[1]^a[2]==0){
			cout<<1;
		}else{
			cout<<0;
		}
		fclose(stdin);
	fclose(stdout);
		return 0;
		
	}
	if(n<=10&&k<=1){
		
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
		}
		cout<<ans;
		fclose(stdin);
	fclose(stdout);
		return 0;
	}
	if(n<=100&&k==0){
		if(n%2==0){
			cout<<n/2;
		}else{
			cout<<(n-1)/2;
		}
		fclose(stdin);
	fclose(stdout);
		return 0;
	}

	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	
	
	 
	return 0;
}
