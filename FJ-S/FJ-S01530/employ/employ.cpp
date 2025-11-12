#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long f(long long a){
	long long k=1;
	for(long long i=1;i<=a;i++){
		k*=i;
		k%=mod;
	}
	return k;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,b=0;
	cin>>n>>m;
	string s;
	cin>>s;
	int a[555];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)b++;
	}
	long long h=(f(m)*f(n-m))%mod;
	long long ans=(f(n)/h)%mod;
	long long g=(ans*f(m))%mod;
	cout<<g;
	return 0;
}
