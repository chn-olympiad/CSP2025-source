#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[5002],ans,an[5002];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+1+n);
	if(n==3&&a[1]+a[2]>a[3]*2)ans=1;
	else{
		for(LL i=3;i<=n;i++){
			ans+=i;
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
