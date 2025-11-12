#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>inline void read(T&x){
	x=0; char c; int sign=1;
	do{c=getchar(); if(c=='-') sign=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	x*=sign;
}

ll n,k,ans;
ll a[500010],cntn,cntm;
bool A=true,B=true,C=true;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n); read(k);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]!=1) A=false;
		if(a[i]>1) B=false;
	}
	if(A){
		cout<<n/2;
		return 0;
	}
	if(B){
		for(int i=1;i<=n;i++){
			if(a[i]==0) cntn++;
			else cntm++;
		}
		if(k==1){
			cout<<cntm;
		}else if(k==0){
			for(int i=2;i<=n;i++){
				if(a[i]==1&&a[i-1]==1){
					cntn++;
					a[i]=0;
				}
			}
			cout<<cntn;
		}
		return 0;
	}
	ll su=0;
	for(int i=1;i<=n;i++){
		su^=a[i];
		if(su==k){
			ans++,su=0;
		}
	}
	cout<<ans;
	return 0;
} 

