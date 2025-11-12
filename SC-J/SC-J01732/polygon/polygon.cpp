#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,m;
	int a[1000],b[1000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
//	for(int i=0;i<m;i++){
//		cin>>b[i];
//	}
	int t=0; 
	for(int i;i<n;i++){
		if(a[i]-a[i+1]==0)
		t++;
	} 
	cout<<t;
	return 0;
} 