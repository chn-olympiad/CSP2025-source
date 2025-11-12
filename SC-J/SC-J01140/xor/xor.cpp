#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,d,l,a[N],b,c[N],dp[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=c[i-1]^a[i];
	}
	for(int r=1;r<=n;r++)
	{
		d=c[r]^k;
		
		//cout<<d<<"-";
		
		l=r-1;
		while(l>=0&&c[l]!=d)
		{
			l--;
			if(dp[l]+1<dp[r-1])
				break;
		}
			
		//cout<<l<<" ";
		dp[r]=max(dp[r-1],dp[l]+1);
		if(l==-1)
		dp[r]=dp[r-1];
		b=max(b,dp[r]);
	}
//	cout<<endl;
//	for(int r=1;r<=n;r++)
//		cout<<c[r]<<" ";
//	cout<<endl;
//	for(int r=1;r<=n;r++)
//		cout<<dp[r]<<" ";
//	cout<<endl;
	cout<<b;
	return 0;
 } 