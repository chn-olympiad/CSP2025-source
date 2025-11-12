#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,t;
int a[20010][3]={0}; 
int am[20010];
int sum;
int sum1[6];
void myd(int w){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i-1][j-1];
		}
		if(a[i-1][0]>=a[i-1][1]&&a[i-1][0]>=a[i-1][2]){
			am[i-1]=a[i-1][0];	
		} 
		if(a[i-1][1]>=a[i-1][0]&&a[i-1][1]>=a[i-1][2]){
			am[i-1]=a[i-1][1];	
		} 
		if(a[i-1][2]>=a[i-1][1]&&a[i-1][2]>=a[i-1][0]){
			am[i-1]=a[i-1][2];	
		} 	
	}
	for(int i=1;i<=n;i++){
		sum=sum+am[i-1];
	}
	sum1[w-1]=sum;
	return;
}
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		sum=0;
		a[20010][3]={0};
		am[20010]={0};	
		cin>>n;
		myd(i);	
	}	
	for(int i=1;i<=t;i++){
		cout<<sum1[i-1]<<endl;	
	}
	return 0;
}
