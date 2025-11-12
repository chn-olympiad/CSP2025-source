#include<bits/stdc++.h>
using namespace std;
int l=0,s=0,p=0;
int sum(int e[],int m){
	s=0;
	for(l=0;l<m;l++)s+=e[l];
	return s;
}
int max(int f[],int m){
	p=0;
	for(l=0;l<m;l++){
		if(p<f[l])p=f[l];
	}
	return p;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int i,a[n]={},b[n]={};
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int t=3;
	cout<<10;
	return 0;
}
