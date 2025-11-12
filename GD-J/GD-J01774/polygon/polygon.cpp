#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int pangduan(int a,int b,int c){
	int max1=max(a,b);
	max1=max(max1,c);
	if(a+b+c>max1*2){
		return 1;
	} 
	else return 0;
}
int a[5005]={};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(pangduan(a[i],a[j],a[k])){
					sum++;
				}
			}
		}
	}
	

	cout<<sum;
	return 0;
}
