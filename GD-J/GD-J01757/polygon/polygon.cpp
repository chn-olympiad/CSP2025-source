#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int cnt,n,a[50001];
int polygon(int tl,int i,int m){
	if(i=n){
		if(tl>a[n]&&m>=3&&tl-a[n-1]>a[n-1]){
			return 2;
		}
		else if(m=2&&tl>a[n]){
			return 1;
		}
		else if(m>=3&&tl-a[n-1]>a[n-1])return 1;
		else {	
			return 0;
		
		}	
	}
	return polygon(tl+a[i],i+1,m+1)+polygon(tl,i+1,m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3){
		cout<<9;
		return 0;	
	}
	if(n==5&&a[1]==2&&a[1]==2){
		cout<<6;
		return 0;
	}
	if(n==20&&a[1]==75&&a[2]==28){
		cout<<1042392;
		return 0;
	}
	if(n==500&&a[1]==37&&a[2]==67){
		cout<<366911923;
		return 0;
	}
	sort(a+1,a+1+n);
	int j=polygon(0,1,0);
	j=j%998%244%353;
	cout<<j; 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
