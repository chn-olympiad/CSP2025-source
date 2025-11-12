#include<bits/stdc++.h>
using namespace std;

int yhh(long long int x,long long int y){
	string xs,ys,zs;
	long long int abcd;
	if(x==0){
		xs="0";
	}else{
		while(x!=1){
			if(x%2==1){
				xs=xs+"1";
			}
			if(x%2==0){
				xs=xs+"0";
			}
			x/=2;
		}
		xs=xs+"1";
	}
	if(y==0){
		ys="0";
	}else{
		while(y!=1){
			if(y%2==1){
				ys=ys+"1";
			}
			if(y%2==0){
				ys=ys+"0";
			}
			y/=2;
		}
		ys=ys+"1";
	}
	if(xs.length()<ys.length()){
		while(xs.length()<ys.length()){
			xs=xs+"0";
		}
	}
	if(ys.length()<xs.length()){
		while(ys.length()<xs.length()){
			ys=ys+"0";
		}
	}
	for(int v=0;v<xs.length();v++){
		if(xs.substr(v,1)!=ys.substr(v,1)){
			zs=zs+"1";
		}else{
			zs=zs+"0";
		}
	}
	long long int tt=0,ll;
	for(int bb=0;bb<zs.length();bb++){
		ll=1;
		if(zs.substr(bb,1)=="1"){
			if(bb==0){
				tt+=1;
			}else{
				for(int ff=1;ff<=bb;ff++){
					ll*=2;
				}
				tt+=ll;
			}
		}
	}
	return tt;
}

long long int n,f,a[100000],c,k,b[100000];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int xt,zz=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			zz+=1;
		}
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=yhh(b[i-1],a[i]);
	}
	xt=0;
	for(int i=1;i<=n/2;i++){
		if(i==1){
			if(b[1]==k){
				xt+=1;
			}
		}else{
			c=yhh(b[i*2-2],b[i*2]);
			if(c==k){
				xt+=1;
			}
		}
	}
	if(xt>zz){
		zz=xt;
	}
	xt=0;
	for(int i=1;i<=n/3;i++){
		if(i==1){
			if(b[1]==k){
				xt+=1;
			}
		}else{
			c=yhh(b[i*3-3],b[i*3]);
			if(c==k){
				xt+=1;
			}
		}
	}
	if(xt>zz){
		zz=xt;
	}
	cout<<zz;
	return 0;
} 
