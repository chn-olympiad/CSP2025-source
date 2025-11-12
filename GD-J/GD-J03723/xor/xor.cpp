#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=0;
	for(int i=1;i<n;i++)
	{
		int j=i+1;
		while(a[i]^a[j]!=k)
		{
			j++;
		}
		i=j+1;
		ans++;
	}
	cout<<ans;
	return 0;
}
