#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],nbk=1,ct;
int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			nbk++;
		}
	}
	if(nbk%n==0){
		ct=nbk/n;
	}else{
		ct=nbk/n+1;
	}
	if(ct%2==0){
		cout<<ct<<" "<<n-(nbk%n-1);
	}else{
		if(nbk%n==0){
			cout<<ct<<" "<<n;
		}else{
			cout<<ct<<" "<<nbk%n;
		}
	}
}
