#include<bits/stdc++.h>
using namespace std;
int main( ){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
		char a;
	int d,e,f,g,h,k,j;
	cin>>a;
	cin>>d;
	a=d;
	e=d%10;
	f=d%100/10;
	g=d/100;
	h=d/1000;
	k=d/10000;
	j=d/100000;
	if(e>f>g>h>k>j) e=e*10000;
	if(f>e>g>h>k>j) f=f*10000;
	if(g>f>e>h>k>j) g=g*10000;
	if(h>f>g>e>k>j) h=h*10000;
	if(k>f>g>h>e>j) k=k*10000;
	if(j>f>g>h>k>e) j=j*10000;
	
	return 0;
} 
