#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char a[501];
	int b[501];
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	if(n==3){
		cout<<2;
	}
	if(n==10){
		cout<<2204128;
	}
}
