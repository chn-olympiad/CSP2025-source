#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],dp[256],f[256],n,k,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int i,j;
	bool A=1,B=1;
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
		if(a[i]!=1) A=0;
		else if(a[i]>1) B=0;
	if(A)
	{
		if(k==1) cout<<n;
		if(k==0) cout<<n/2;
		return 0;
	}
	else if(B)
	{
		int sum=0;
		for(i=1;i<=n;i++) sum+=a[i];
		if(k==1) cout<<sum;
		if(k==0) cout<<n-sum;
		return 0;
	}
	for(i=0;i<256;i++) f[i]=-1;
	dp[a[1]]=f[a[1]]=1;
	for(i=2;i<=n;i++)
	{
		dp[a[i]]=max(0,f[a[i]])+1;
		if(a[i]!=0)
		for(j=0;j<=k;j++)
		{
			if(f[j]!=-1&&f[j^a[i]]!=-1)
				dp[j]=max(dp[j],f[j^a[i]]+max(0,f[j]));
		}
		for(j=0;j<=k;j++) f[j]=dp[j];
	}
	cout<<f[k];
	return 0;
}

