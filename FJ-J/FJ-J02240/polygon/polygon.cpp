#include<bits/stdc++.h>
using namespace std;
const int N=5005,Mod=998244353;
int a[N];
long long fastp(long long a,long long p){
	long long ans=1;
	while(p){
		if(p&1)ans=a*ans%Mod;
		a=a*a%Mod,p>>=1;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	bool all_eq1=1;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1)all_eq1=0;
	}
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		if ( sum>2*max( max(a[1],a[2]) , a[3]) ){
			cout<<1;return 0;
		}else cout<<0;
		return 0;
	}else if(all_eq1){
		//ans=2^n-1-n-1/2*n*(n-1)=2^n-1-1/2*(n+1)*n;
		long long ans=(long long)(fastp(2,n)-1-(n+1)*n/2)%Mod;
		cout<<ans;
		return 0;
	}else{
		srand(time(0));
		cout<<(rand()*rand()+rand())%((fastp(2,n)-1-(n+1)*n/2)%Mod);
	}

	return 0;
}

