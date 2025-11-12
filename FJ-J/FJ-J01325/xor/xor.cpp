#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],sum;
string k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k=="0")
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1&&a[i+1]==1)
			{
				sum++;
				i++;
			}
			else if(a[i]==0)
			{
				sum++;
			}
		}
	}
	else if(k=="1")
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
			{
				sum++;
				i++;
			}
			else if(a[i]==1)
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}