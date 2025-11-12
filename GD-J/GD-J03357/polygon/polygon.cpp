#include<bits/stdc++.h>
using namespace std;
long long n,c,w,r,i,j,k,a[5005],dp[5005];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=dp[0]=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(w=i=1;i<=n;i++){
		for(c=j=0;j<=a[i];j++)(c+=dp[j])%=998244353;
		r=(r+w-c+998244353)%998244353;
		for(j=5000;j>=a[i];j--)(dp[j]+=dp[j-a[i]])%=998244353;
		w=w*2%998244353;
	}
	return cout<<r,0;
}
//AK at 9:53
