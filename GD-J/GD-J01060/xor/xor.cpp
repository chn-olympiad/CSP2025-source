#include<bits/stdc++.h>
using namespace std;

const int N=500010;
int a[N],sum[N],k,n,lea=1;
long long ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=lea;j<=i;j++)
		{
			if((sum[i]^sum[j-1])==k||(i==j&&a[i]==k))
			{
				ans++;
				lea=i+1;
				break;
			}	
		}
	}
	cout<<ans;
	return 0;
}
