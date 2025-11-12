#include<bits/stdc++.h>
using namespace std;
//What the hell? What's this?
const long long MOD=998244353;
long long n,a[5000];
struct stm{
	long long total,maxl;
};
long long stick(long long num,long long deep,long long mod,stm q,long long sum){
	long long f=0;
	if(deep>num){
		return q.total>q.maxl*2;
	}
	for(long long i=deep;i<n;i++){
		stm p;
		p.maxl=max(a[i],q.maxl);
		p.total=q.total+a[i];
		f+=stick(num,i+1,mod,p,sum)%mod;
	}
	return (sum+f)%mod;
}
long long polygon(long long mod){
	long long p=0;
	for(long long i=2;i<n;i++){
		stm q;
		q.maxl=0;
		q.total=0;
		p+=stick(i,0,mod,q,0);
	}
	return p%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<polygon(MOD);
	return 0;
}
