#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int a=0;
	a=n*m;
	int ar[a];
	for(int i=0;i<a;i++)
	{
		cin>>ar[i];
	}
	int z,d=0;
	z=ar[0];
	for(int i=0;i<a;i++){
		for(int j=1;j<a;j++){
			if(ar[i]>ar[i-1])
			{
				int b=0;s
				b=ar[i];
				ar[i]=ar[i-1];
				ar[i-1]=ar[i];
			}
		}
	}
	for(int i=0;i<a;i++){
		if(z==ar[i])
		{
			d=i+1;
		}
	}
	int c,r;
	c=d/n+1;
	if(c%2==0){
		r=(c*n)-d;
	} else {
		if(d%n==0);
		{
			r=n;
		} 
		if(d%n!=0){
			r=d%r;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
