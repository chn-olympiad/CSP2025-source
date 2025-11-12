#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2 ;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2 ;i -= s3)
#define INF 0x7f7f7f7f
#define ll long long
using namespace std;
int n,k,a[500010],s[500010],dp[500010];
map <int,int> f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int i;
	rep(i,1,n,1){
		cin>>a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	f[0] = 0;
	rep(i,1,n,1){
		if(f.count(s[i] ^ k)) dp[i] = max(dp[i - 1],f[s[i] ^ k] + 1);
		else dp[i] = dp[i - 1];
		f[s[i]] = max(f[s[i]],dp[i]);
	}
	cout<<dp[n];
	return 0;
}
