#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m,c,r,s,d;
	cin>>n>>m;
	s=m*n;
	int a[10001];
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	d=a[1];
	for(int i=2;i<=s;i++){
		for(int j=1;j<=s-1;j++){
			if(a[j]<=a[i]){
				swap(a[j],a[i]);
			}
		}
	}
	int i;
	for(i=1;i<=s;i++){
		if(a[i]==d){
			break;
		}
	}
	int l,h;
	c=i/n;
	h=i%n;
	if(m!=0){
		l++;
	}
	if(h%2==0){
		cout<<m<<' ';
		if(h==0){
			r=1;
			cout<<r;
		}
		else{
			r=n-h+1;
			cout<<r;
		}
	}
	else{
		cout<<c<<' ';
		if(h==0){
			r=n;
			cout<<r;
		}
		else{
			r=h;
			cout<<r;
		}
	}
	return 0;
}
