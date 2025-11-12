#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int a[6000],n,all,x,y;
int check(){
	int mx=0,al;
	if(n<3)return 0;
	for(int i=x;i<=y;i++){
		mx=max(mx,a[i]);
		al+=a[i];
	}
	if(al>mx*2)return 1;
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=2;j<=n-i;j++){
			x=i;
			y=x+j;
			if(check())all=(all+1)%998244353;
		}
	}
	cout<<all;
	return 0;
}
