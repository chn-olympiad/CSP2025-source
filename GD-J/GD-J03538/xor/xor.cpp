#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
long long a[N],max1[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long sum=0;
		for(int j=i;j>=1;j--)
		{
			sum^=a[j];
			if(sum==k)
			{
				dp[i]=max(dp[i],max1[j-1]+1);
				break;
			}
		}
		max1[i]=max(dp[i],max1[i-1]);
	}
	cout<<max1[n];
	return 0;
}
