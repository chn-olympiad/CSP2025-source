#include <bits/stdc++.h>
using namespace std;
const long long N=5e3+7;
const long long M=998244353;
int n,x;
long long sum,cnt,ans,ma,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (long long i=7;i<=(1<<n);i++){
		cnt=0;
		for (long long j=0;j<i;j++){
			if(i&(1<<j)) cnt++;
		}
		if(cnt>=3){
			sum=0,ma=0;
			for (long long j=0;j<i;j++){
				if((1<<j)&i){
					sum+=a[j+1];
					ma=max(a[j+1],ma);
				}
			}
			if(2*ma<sum) ans++;
		}
	}
	cout<<ans%M;
	return 0;
}
