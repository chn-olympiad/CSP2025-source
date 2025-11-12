#include<bits/stdc++.h>
//#Shang4Shan3Ruo6Shui4
using namespace std;
long long n,k;
long long maxn[500010];
long long a[500010];
long long dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		long long p=0,sum=0;
		for(int j=i;j>=1;j--)
		{
			p=p^a[j];
			long long q=0;
			if(p==k) q=1;
			sum=max(sum,maxn[j-1]+q);
			if(q==1||maxn[j-1]+q<sum) break;
		}
		dp[i]=sum;
		maxn[i]=max(maxn[i-1],dp[i]);
	}
	cout<<dp[n];
	return 0;
}
/*
4 2
2 1 0 3
*/
