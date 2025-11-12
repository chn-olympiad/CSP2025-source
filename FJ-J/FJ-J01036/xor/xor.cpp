#include <bits/stdc++.h>
using namespace std;
int n;
long long k,sum;
bool flag=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flag=0;
		}
	}
	if(flag)
	{
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(k==1)
		{
			if(a[i]!=a[i+1])
			{
				sum++;
				i++;
			}
			else if(a[i]==a[i+1]&&a[i+1]==a[i+2])
			{
				sum++;
				i+=2;
			}
		}
		else{
			if(a[i]==a[i+1])
			{
				sum++;
				i++;
			}
			else if(a[i]!=a[i+1]&&a[i]==a[i+2]||a[i]!=a[i+1]&&a[i+1]==a[i+2]||a[i]!=a[i+2]&&a[i+1]==a[i+2]||a[i]!=a[i+2]&&a[i+1]==a[i]||a[i+2]!=a[i+1]&&a[i]==a[i+2]||a[i+2]!=a[i+1]&&a[i+1]==a[i])
			{
				sum++;
				i+=2;
			}
		}
	}
	cout<<sum;
	return 0;
}
