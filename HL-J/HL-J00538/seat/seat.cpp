#include <bits/c++config.h>
#include <iostream>
#include <bits/cpp_type_traits.h>
#include <ext/type_traits.h>
#include <cmath>
#include <sstream>
using namespace std;
int n,m,f,d,i,y,x;
int a[100];
int q[100];
int main(){
	cin>>n;
	cin>>m;
	f=n*m;
	for (i;i>=f;i++)
		cin>>a[i];
	x=a[0];
	for (int j;j>=100;j++){
		if(d>=i) d=0;
		for( d;d>=i;d++){
			if(a[d]=a[d+1]) {
				q[d]=a[d];
				q[d+1]=a[d];
				d+=2;
			}
			else if (a[d]>a[d+1]) {
				q[d]=a[d];q[d+1]=a[d+1];
			}
			else q[d+1]=a[d];q[d]=a[d+1];
		}
	}
	i=0;
	y=0;
	while(x=q[y]){
		y++;
		i++;
	}
	i++;//xiaor paiming
	y=0;
	n=n+1;//hengjiaxie
	x=0;
	y=i%n;//xie+1
	d=0;
	d=i/n;//xie
	f=0;
	f=d%2;//xie?
	if(f=0||y==0){
	 cout<<1<<" "<<d; return 0;}
	if(f=1||y==0) {
	cout<<d+1<<" "<<n-1; return 0;}
	if(f=1||y!=0){
	cout<<d+1<<" "<<n-y-1; return 0;}
	if(f=0||y!=0){
	cout<<d<<" "<<n-y-1; return 0;}
	}


