#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,h[5005],dp[25000005]{1};
int main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	F;
	int i,j,k,s,cnt=0;
	cin>>n;
	for(i=0;i<n;++i)cin>>h[i];
	sort(h,h+n);
	for(i=s=0;i<n-1;++i){
		s+=h[i];
		for(j=s;j>=h[i];--j)dp[j]=(dp[j]+dp[j-h[i]])%998244353;
		for(j=h[i+1]+1,k=0;j<=s;++j)k=(k+dp[j])%998244353;
		cnt=(cnt+k)%998244353;
	}
	cout<<cnt<<endl;
	return 0;
}
