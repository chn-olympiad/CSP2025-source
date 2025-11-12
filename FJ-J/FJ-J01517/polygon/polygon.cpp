#include<bits/stdc++.h>
using namespace std;
int n,num,a[5005];
int three(int z,int b,int c){
	int x[4]{0,z,b,c};
	sort(x+1,x+4);
	if(x[3]<x[2]+x[1])return 1;
	return 0;
}
int four(int z,int b,int c,int d){
	int x[5]{0,z,b,c,d};
	sort(x+1,x+5);
	if(x[4]<(x[3]+x[2]+x[1]))return 1;
	return 0;
}
int five(int z,int b,int c,int d,int e){
	int x[6]{0,z,b,c,d,e};
	sort(x+1,x+6);
	if(x[5]<(x[3]+x[2]+x[1]+x[4]))return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		sort(a+1,a+n+1);
		//cout<<a[3]<<a[2]<<a[1];
		if(a[3]<(a[2]+a[1]))cout<<1;
		else cout<<0;
	}
	if(n==4)cout<<three(a[1],a[2],a[3])+three(a[1],a[2],a[4])+three(a[1],a[3],a[4])+three(a[2],a[3],a[4])+four(a[1],a[2],a[3],a[4]);
	if(n==5)cout<<three(a[1],a[2],a[3])+three(a[1],a[2],a[4])+three(a[1],a[2],a[5])+three(a[1],a[3],a[4])+three(a[1],a[3],a[5])+three(a[1],a[4],a[5])+three(a[2],a[3],a[4])+three(a[2],a[3],a[5])+three(a[1],a[4],a[5])+four(a[1],a[2],a[3],a[4])+four(a[1],a[2],a[3],a[5])+four(a[1],a[2],a[4],a[5])+four(a[5],a[2],a[3],a[4])+four(a[1],a[5],a[3],a[4])+five(a[1],a[2],a[3],a[4],a[5]);
	
}

