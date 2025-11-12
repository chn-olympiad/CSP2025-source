#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,ks,R,wz,b;
	cin>>n>>m;
	ks=n*m;
	int gc[ks]={};
	int gp[ks]={};
	for(int i=0;i<ks;i++){
		cin>>gc[i];
	}
	R=gc[0];
	int maxx=0;
	for(int a=0;a<ks;a++){
		for(b=0;b<ks;b++){
			if(maxx<gc[b]){
				maxx=gc[b];	
			}
		}
		for(int c=0;c<ks;c++){
			if(gc[c]==maxx){
				gc[c]=0;
			}
		}
		gp[a]=maxx;
		maxx=0;
	}
	
	for(int i=0;i<ks;i++){
		if(gp[i]==R){
			wz=i+1;
			break;
		}
	}
	int c,r,r1;
	if(wz<n||wz==n){
		c=1;
	}
	else{
		c=((wz-(wz%n))/n)+1;
	}
	
	r1=c%2;
	if(r1==1){
		r=wz-(n*(c-1));
	}
	else{
		r=n-wz%n+1;
	}
	cout<<c<<' '<<r;
}
