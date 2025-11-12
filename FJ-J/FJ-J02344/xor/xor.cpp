#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
bool A=1,B=1;
inline int read()
{
	int x=0,q=1;
	char c=getchar();
	while(c<'0'||'9'<c)
	{
		if(c=='-') q=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*q;
 } 
long long solve()
 {
	long long f[5005][5005],dp[5005];
	for(int i=0;i<=n;i++) dp[i]=0;
	for(int r=1;r<=n;r++)
	{
		f[r][r]=0;			
		dp[r]=dp[r-1];
		for(int l=1;l<=r;l++)
		{
			int x=f[l][r-1]^a[r];
			f[l][r]=x;

			if(f[l][r]==k) dp[r]=max(dp[r],dp[l-1]+1);
		} 
	} 
	return dp[n];
 } 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]!=a[1]) A=0;
		if(a[i]!=0&&a[i]!=1) B=0;
	}
	if(A&&k==0)
	{
		if(a[1]==0) cout<<n;
		else cout<<n/2;
		return 0;
	}
	if(B&&k==1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=a[i];
		cout<<cnt;
		return 0; 
	}
	if(k==0)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) cnt++;
			else if(a[i+1]==a[i])
			{
				cnt++;
				i=i+1;
			}
		}
		cout<<cnt;
		return 0;
	}
	cout<<solve();
	return 0;
}
