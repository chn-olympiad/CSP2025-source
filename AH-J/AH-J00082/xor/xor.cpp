#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],s[N],dp[N],n,k,ans=0;
map<int,int> mp;
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]^a[i];
	mp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(mp.count(s[i]^k)) dp[i]=max(dp[i],mp[s[i]^k]+1);
		mp[s[i]]=max(mp[s[i]],dp[i]);
	}
	cout<<dp[n]<<"\n";
	return 0;
}
