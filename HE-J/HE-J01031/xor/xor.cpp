#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],z,ans,u[N]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			z=0;
			for (int c=i;c<=j;c++)
			{
			z=z^a[c];	
			}
			if (z==k)
			{
			ans++;				
			}
		}
	}
	cout<<ans;
	return 0;
}
