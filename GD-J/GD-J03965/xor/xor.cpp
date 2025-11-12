#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+4;
const int R=1<<22;
ll n,k,a[N],s[N],dp[N],ans[R];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=max((ll)(s[i]==k),dp[i-1]);
		ll now=s[i]^k;
		dp[i]=max(dp[i],ans[now]);
		ans[s[i]]=max(ans[s[i]],dp[i]+1);
	}
	cout<<dp[n];
	return 0;
}
