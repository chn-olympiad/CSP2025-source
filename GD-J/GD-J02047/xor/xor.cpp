#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[601001],s[601010],tot[601010],add[601010],dp[601010],sum;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=(1<<19);i++)tot[i]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		add[i]=tot[s[i]^k];
		tot[s[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(add[i]!=-1)dp[i]=dp[add[i]]+1;
		dp[i]=max(dp[i-1],dp[i]);
	}
	cout<<dp[n];
	return 0;
}//tell you a secert ,my friend who is called hlcg(because of his wrong,he is named liangcha_memory now) in luogu love a girl named LJN for the reason that she looks like six flower
//don't tell others ,or i will be ### by him
