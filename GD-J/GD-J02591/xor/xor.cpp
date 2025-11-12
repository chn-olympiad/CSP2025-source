#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=5e5+6;
ll n,k;
ll a[N],dp[N];
ll f(ll s,ll sum)
{
	if(s==n) return sum;
	for(int i=s;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(int(dp[j]^dp[i])== k)
			{
				sum++;
				sum=f(j,sum);
				
				return sum;
			}
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i]=a[i] ^ dp[i-1];
	}
	cout<<f(0,0);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
