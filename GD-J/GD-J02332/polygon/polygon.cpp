#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace{
	int ans=0,a[5005],n,dp[25000005],N;
	constexpr int mod=998244353;
	int solve(int x,int y){
		int X=0;
		for(int i=N;i>=a[x];i--) (dp[i]+=dp[i-a[x]])%=mod;
		for(int i=y+1;i<=N;i++) X+=dp[i],X%=mod;
		return X;
	}
	void Main(){
		dp[0]=1;
		cin.tie(0)->sync_with_stdio(0);
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1),N=a[1];
		for(int i=2;i<=n;i++) N+=a[i],(ans+=solve(i-1,a[i]))%=mod;//subset count: sum>a[i]
		cout<<ans;
		//O(n^2*V).大有前途
		//预期：80pts
	}	
} 
main(){Main();}
//CCF 求你了给我 380pts 吧！！！！！11111 I Love CCF!
//luogu uid:1373205
//我要上迷惑行为大赏！ 

