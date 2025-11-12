#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const long long p=998244353;
long long n,a[5010],ans;
long long qpow(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1ll)res=(res*a)%p;
		b>>=1ll;
		a=(a*a)%p;
	}
	return res;
}
int main(){
	ios
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(long long i=0;i<(1ll<<n);i++){
			long long mx=0,sum=0,cnt=0;
			for(long long j=1;j<=n;j++){
				if(i&(1ll<<(j-1))){
					++cnt;
					sum+=a[j];
					if(mx<a[j])mx=a[j];
				}
			}
			if(cnt>=3&&sum>2*mx)++ans;
		}
		cout<<ans;
	}else{
		cout<<(qpow(2,n)-1-n-n*(n-1)/2+p)%p; 
	}
	return 0;
}
