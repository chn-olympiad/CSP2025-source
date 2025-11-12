#include <iostream>
#include <cstring>

using namespace std;

const int N=500005;

int n,k,a[N];
int dp[N],p[(1<<20)+50];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	memset(p,-1,sizeof(p));
	
	p[0]=0;
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i],a[i]^=a[i-1];
		p[a[i]]=i;
		if(p[a[i]^k]>=0) dp[i]=dp[p[a[i]^k]]+1;
		dp[i]=max(dp[i],dp[i-1]);
	}
	
	cout<<dp[n];
	return 0;
}
