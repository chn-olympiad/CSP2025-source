#include<bits/stdc++.h>
using namespace std;
long long aa,bb=0,a,b,c,d,e,g=0,h=1,i,j,k[1000004],f[1000004];
void qq(long long x,long long s,long long m){
	if(x>a){
		if(s>2*m){
			g++;
		}
	}else{
		qq(x+1,s+k[x],max(m,k[x]));
		
		qq(x+1,s,m);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(i=1;i<=a;i++){
		cin>>k[i];
		if(k[i]!=1){
			h=0;
		}
	}
	if(h==1){
		f[1]=1;
		
		for(i=2;i<=a;i++){
			f[i]=f[i-1]*i;
		}
	for(i=3;i<a;i++){
		d=i;
		d=f[a]/(f[a-d]*f[d]);	
		bb=bb+d;
	}
	cout<<bb+1;
	return 0;
	}
	qq(1,0,0);
	cout<<g;
	return 0;
} 

