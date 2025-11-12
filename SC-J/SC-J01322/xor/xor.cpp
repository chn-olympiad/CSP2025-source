#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500005],b[500005]={0};
long long ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			long long h=b[j]^b[i-1];
			if(h==k)
			{
				ans++;
				i=j+1;
			}
		}
	}
	cout<<ans;
	return 0;
}