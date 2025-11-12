#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long  k[10000000]={};
	long long a,b,c,d,e,f;
	cin>>a>>b;
	for(int x=0;x<(a*b);x++){
		cin>>k[x];
	}
	c=k[0];
	f=(a*b);
	sort(k,k+f,greater<long>());
	for(int x=0;x<a*b;x++){
		d=k[x];
		if(d==c){
			d=x;
			break;
		}
	}
	e=(d+1)/a;
	if((d+1)/a==0){
		cout<<e<<" ";
	}else{
		cout<<e+1<<" ";
	}
	d=(d+1)%a;
	if(e%2==0){
		d=a-d;
		cout<<d;
	}else{
		d=d+1;
		cout<<1;
	}	
	
	
	
	
	return 0;
	}
