#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#define int long long 
#define N 500005
using namespace std;
int n,k,a[N],pre[N],dp[N];
int ans;
int mmax[N];
map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],pre[i]=pre[i-1]^a[i];
	mp[0]=0;
	for(int i=1;i<=n;i++){
		int pos=mp[pre[i]^k];
		if(pos||(pre[i]^k)==0)
			dp[i]=mmax[pos]+1;
		mmax[i]=max(mmax[i-1],dp[i]);
		mp[pre[i]]=max(mp[pre[i]],i);
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
