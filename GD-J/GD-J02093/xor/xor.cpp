#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s[500010],dp[500010];
unordered_map<int,int> last;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k,last[0]=1;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++)dp[i]=max(dp[i-1],last[s[i]^k]),last[s[i]]=dp[i]+1;
	cout<<dp[n];
}
