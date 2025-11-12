#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;

ll n,k,a[N];
ll prexor[N],g[N],dp[N];
unordered_map<ll,ll> last;

int main(){
	
	//别忘了最后写 freopen~ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
		
		prexor[i]=prexor[i-1]^a[i];
		g[i]=prexor[i]^k;
	}
	
	for(int i=1;i<=n;i++){
		
		dp[i]=dp[i-1];
		
		if(last[g[i]]||prexor[i]==k) dp[i]=max(dp[i],dp[last[g[i]]]+1);
		
		last[prexor[i]]=i;
	}
	
	cout<<dp[n]<<'\n';
	
	return 0;
}
//9:19 meaw!
