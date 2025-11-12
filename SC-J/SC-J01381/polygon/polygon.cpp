#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,a[5050];
int num,pf[5050];
int op2(int x,int y){//
	return x-1;
}
int op1(int x){
	int cnt=0;
	for(int i=2; i<x; i++){
		cnt+=(op2(i,x)*pf[x-1-i]);
		cnt%=mod;
	}
	return cnt;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	pf[0]=1;
	for(int i=1; i<=5050; i++){
		pf[i]=pf[i-1]*2;
		pf[i]=pf[i]%mod;
	}
    //1 1 1 1 1 1 1 1 1 
    cin>>n;
    for(int i=1; i<=n; i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			num=1;
		}
		else{
			num=0;
		}
	}
	else{
		for(int i=3; i<=n; i++){
			num+=op1(i);
			num%=mod;
		}
	}
	cout<<num;
	return 0;
}