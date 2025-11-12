#include<iostream>
#include <bits/requires_hosted.h>
#include<algorithm>
#include<stdio.h>
#include<ostream>
#include<string>
#include<cmath>
using namespace std;
int a[5010];
int f[5010];
int f1[5010];
int n;
int t=0;
bool ppp(int i,int j){
	int sum=0;
	int big=0; 
	
		for(int k=i;k<=j;k++){
			sum+=a[k];
			big=max(big,a[k]);
		}
		if(sum>big){
			return true;
		}else{
			return false;
		}
	return false;
}
int choose(){
	int sum=0;
	
	for(int k=3;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=i+k;j++){
				if(ppp(i,j)==true){
					sum++;
				}
				t++;
			}
		}
	}
	return sum;
}
void find(){
	for(int i=1;i<=n;i++){
		f[i]=max(f[i]+a[i],f[i-1]);
		
		cout<<f[i]<<" ";
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n==3){
		int sum=0;
		int big=0; 
	
		for(int k=1;k<=3;k++){
			sum+=a[k];
			big=max(big,a[k]);
		}
		
		if(sum>big){
			cout<<1;
		}else{
			cout<<0;
		}
		fclose(stdin);
	fclose(stdout);
	return 0;
	}
	int tt=choose();
	cout<<tt;
	
	fclose(stdin);
	fclose(stdout);
	
	
	
	
	 
	return 0;
}
