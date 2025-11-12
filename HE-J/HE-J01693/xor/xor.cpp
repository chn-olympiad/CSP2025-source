#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],f[N],dp[N][2];
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]^=a[i-1],mp[a[i]]=0,mp[a[i]^k]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if((a[mp[a[i]^k]]^a[i])==k)dp[i][1]=dp[mp[a[i]^k]+1][0]+1;
		mp[a[i]]=i;
	}
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
}
