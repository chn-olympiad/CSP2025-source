#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500004,maxs=(1<<20)+528;
int n,k;
int a[maxn],s;
int lst[maxs];
int dp[maxn];
inline void chkx(int &x,int y){x=max(x,y);}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	memset(lst,-1,sizeof(lst));lst[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];s^=a[i];
		if(~lst[k^s]) dp[i]=dp[lst[k^s]]+1;
		else dp[i]=0;
		chkx(dp[i],dp[i-1]);
		lst[s]=i;
	}
	cout<<dp[n]<<'\n';
	return 0;
}
