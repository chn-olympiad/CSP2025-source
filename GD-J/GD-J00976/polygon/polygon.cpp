#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[5007],b;
long long n,sum,ans,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(long long i=4;i<(1<<n);i++){
			sum=0;
			b=0;
			cnt=0;
		for(int j=0;(1<<j)<=i;j++){	
			if(i&(1<<j)) {
				cnt++;
				sum=(sum+a[j])%mod;
				b=max(b,a[j]);
			}
		}
		if(cnt>=3&&sum>b*2) {
			ans=(ans+1)%mod;	
		}
	}
	cout<<ans;
	return 0;
} 
