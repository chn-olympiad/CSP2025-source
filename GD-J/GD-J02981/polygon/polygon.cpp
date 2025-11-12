#include<bits/stdc++.h>
using namespace std;
long long n,a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=3) cout<<1;
	else{
		sort(a+1,a+1+n);
		long long sum,ans=0;
		for(int i=3;i<=n;i++){
			sum=0;
			sum+=n;
			for(int j=n-1;j>=n-i+1;j--) sum*=j,sum%=998244353;
			for(int j=1;j<=i;j++) sum/=j;
			ans+=sum;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
