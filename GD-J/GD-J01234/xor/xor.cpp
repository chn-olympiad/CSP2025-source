#include <bits/stdc++.h>
using namespace std;
const int N=5e5+8;
int n,k,a[N],dp[N],ans[N],s[N];
const int K=(1<<21)+100;
int mp[K]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(mp,0,sizeof(mp));
	cin >>n>>k;
	for (int i=1;i<=n;++i)
		cin >>a[i];
	s[1]=a[1];
	for (int i=2;i<=n;++i) s[i]=s[i-1]^a[i];
	mp[0]=1;
	for (int i=1;i<=n;++i){
		dp[i]=mp[s[i]^k];
		mp[s[i]]=i+1;
	}
	int maxn=-1e9;
	ans[1]=dp[1];
	for (int i=2,j=0;i<=n;++i){
		for (;j<dp[i];++j)
			maxn=max(maxn,ans[j]);
		ans[i]=max(ans[i-1],maxn+1);
	}
	cout <<ans[n];
	return 0;
}
