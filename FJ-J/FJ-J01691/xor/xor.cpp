#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout<<#x<<'='<<x<<endl;
#define ll long long
int a[500010];
int dp[500010];
int yh[500010];
int lst[5000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],yh[i]=yh[i-1]^a[i];
	memset(lst,-1,sizeof(lst));
	for(int i=1;i<=n;i++){
		int pos=-1;
		int j=k^yh[i];
		pos=lst[j];
		if(j==0&&pos==-1)pos=0;
		if(pos==-1)dp[i]=dp[i-1];
		else{
			if(dp[i-1]>dp[pos]+1)dp[i]=dp[i-1];
			else dp[i]=dp[pos]+1;
		}
		lst[yh[i]]=i;
		//dbg(dp[i])
		//dbg(j)
		//dbg(pos)
	}
	cout<<dp[n]<<endl;
	return 0;
}
