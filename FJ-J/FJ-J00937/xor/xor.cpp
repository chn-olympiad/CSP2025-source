#include<bits/stdc++.h>
using namespace std;
const int MAXN=pow(2,20)+5;
int n,k;
int ans=0;
int dp[500005];
long long a[500005];
long long b[500005];
int jl[MAXN];
int last=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=(b[i-1]^a[i]);
		dp[i]=dp[i-1];
		if(a[i]==k)dp[i]++;
		else if(jl[(b[i]^k)])dp[i]=max(dp[i],dp[jl[(b[i]^k)]]+1);
		jl[b[i]]=i;
	}
	cout<<dp[n];
	return 0;
}

