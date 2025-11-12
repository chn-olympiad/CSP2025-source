#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n]={};
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i = 0;i<n;i++){
		for(int j = 1;j<n;j++){
			for(int k = 2;k<n;k++){
				if((a[i]+a[j]+a[k])>max(a[i],max(a[j],a[k]))*2){
				sum++;
				}
			}
		}
	}
	for(int i = 0;i<n-4;i++){
		if((a[i]+a[i+1]+a[i+2])>max(a[i],max(a[i+1],max(a[i+2],a[i+3])))*2){
			sum++;
		} 
	}
	cout<<(sum%998244353)/5;
	return 0;
}
