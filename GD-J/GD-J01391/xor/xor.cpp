#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000000],ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int j,s=0;
		for(j=i;j<=n;j++)
		{
			s^=a[j];
			if(s==k)
			{
				break;
			}
		}
		if(s==k)
		{
			ans++;
			i=j;
		}
	}
	cout<<ans;
	return 0;
}
