#include<bits/stdc++.h> 
using namespace std;
long long a=0,b,k;
long long c[1000003];
int as(int i){
	int h=a+c[i],y=a-c[i],zx,zz;
	if(y<0)y=-y;
	if(h==k){
		return i;
	}
	if(y==k){
		return i;
	}
	if(i==b){
		return 1000000;
	}
	a=h;
	zx=as(i+1);
	a=y;
	zz=as(i+1);
	return min(zx,zz);
}
int main(){
	cin>>b>>k;
	int s=0,zs=0,gpw=1000000;
	for(int i=1;i<=b;i++){
		cin>>c[i];
	}
	for(int i=1;i<=b;i++){
		int g=as(i);
		a=0;
		if(g!=1000000){
			if(i<=s&&g-i<gpw){
				gpw=g-i;
				s=g;
				
			}
			if(i>s){
				zs++;
				gpw=g-i;
				s=g;
				
			}
			
			
		}
	}cout<<zs;
	return 0;
}
