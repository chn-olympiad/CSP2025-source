#include<bits/stdc++.h>
using namespace std;
long long n,a[500005];
long long mod=998244353; 
long long cnt=0;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<(1<<(n+1));i++){
		long long ans=-1,sum=0,kk=0;
		for(int j=1;j<=n;j++){
			if(1&(i>>(j-1))){
				ans=max(ans,a[j]);
				sum+=a[j];
				kk++;
			}
		}
		if(sum>2*ans&&kk>=3){
			cnt++;
		}
	}
	cout<<(cnt/2)%mod;
	return 0;
}
