#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long sum[5005]={0};
long long Kind=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int l=0;l<=n;l++){
		for(int r=l+2;r<=n;r++){
			int maxa=0;
			for(int k=l;k<=r;k++){
				maxa=max(a[k],maxa);
			}
			if(sum[l]-sum[r-1]>maxa*2){
				Kind++;
			}
		}
	}
	cout<<Kind%988244353; 
	return 0;
} 
