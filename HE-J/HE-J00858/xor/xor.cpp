#include<bits/stdc++.h>
using namespace std;
const int N=5*pow(10,5)+10;
long long n,k,a[N],dp[N],x=1,sum;
int f(int n){
	long long s=0;
	for(int i=7;i>=0;i++){
		if(n>=pow(2,i)){
			s+=pow(10,i);
			n-=pow(2,i);
		}
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k&&i!=1&i!=n)cout<<3;
		else cout<<2;
	}
	return 0;
}
