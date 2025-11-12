#include<bits/stdc++.h>
using namespace std;
int a[500005],p[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]=p[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(p[j]^p[i-1]^k==0)
			{
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout<<ans;
}
