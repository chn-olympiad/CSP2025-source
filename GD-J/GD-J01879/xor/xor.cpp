#include <bits/stdc++.h>
using namespace std;
int n,k,ans,a[500007];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;)
	{
		int x=0,sum=0;
		for(int j=i;j<=n;j++)
		{
			x=x | a[j];
			if(x==k)
			{
				i=j+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
}
