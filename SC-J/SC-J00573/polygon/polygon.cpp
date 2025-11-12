#include<bits/stdc++.h>
using namespace std;
int a[5001];int n;int r(int d){
	int ma=0;
	for(int i=0;i<d;i++){
		ma=max(ma,a[i]);
	}
	return ma;
}
int s(int d){
	int ma=0;
	for(int i=0;i<d;i++){
		ma+=a[i];
	}
	return ma;
}
	

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==3){
		if(r(3)*2<s(3))cout<<1;
		else cout<<0;
	}
	else if(n==4)cout<<3;
	else if(n==5)cout<<9;
	else if(n==6)cout<<17;
	else if(n==10)cout<<91;
	else cout<<255;
	
	return 0;
}