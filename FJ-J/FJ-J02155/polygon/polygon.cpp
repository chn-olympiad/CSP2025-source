#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int qpow(int a,int b){
	if(a==1){
		return 1;
	}
	if(b==1){
		return a;
	}
	
	if(b==0){
		return 1;
	}
	long long t=qpow(a,b/2);
	if(b%2==0){
		return (t*t)%mod;
	}
	else{
		return ((t*t)%mod)*a%mod;
	}
}
int a1[100];
int a[10086];
int ans=0;
void makeC(int n,int k,int last,int fullk){
	if(k==0){
		int sum=0;
		int maxa=0;
		for(int i=1;i<=fullk;i++){
			sum+=a[a1[i]];
			maxa=max(maxa,a[a1[i]]);
			//cout<<a1[i]<<' ';
		}
		ans+=(sum>maxa*2);
		//cout<<endl;
		return;
	}
	for(int i=last+1;i<=n;i++){
		a1[k]=i;
		makeC(n,k-1,i,fullk);
		a1[k ]=0;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n>20){
		cout<<qpow(2,n)-n*(n+1)/2;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=3;i<=n;i++){
			makeC(n,i,0,i);
		}
		cout<<ans%mod;
	}
}
/*
2^n-C^2_n-n
*/
