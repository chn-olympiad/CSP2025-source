#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0,s=0;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int l=i;l>=s;l--)
		{
			sum^=a[l];
			if(sum==k)
			{
				ans++;
				s=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
