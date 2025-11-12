#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
const int N=1e6+6;int a[N];
int cnt[N],dp[N];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;f(i,1,n)cin>>a[i];
	f(i,0,1e6)cnt[i]=-1;
	int num=0;cnt[0]=0;f(i,1,n){
		num=num^a[i];int x=(num^k);
		if(cnt[x]!=-1)dp[i]=max(dp[cnt[x]]+1,dp[i-1]);
		else dp[i]=dp[i-1];
		cnt[num]=i;
	}
	cout<<dp[n];
}