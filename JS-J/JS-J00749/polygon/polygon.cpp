#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,ans;
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<i;j++){
			long long cnt=0;
			for(long long k=j;k<=i;k++){
				cnt+=a[k];
			}
			if(cnt>a[i]*2) ans++;
		}
	}
	cout<<ans%MOD;
	return 0;
}
