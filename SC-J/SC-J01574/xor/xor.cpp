#include<bits/stdc++.h>
using namespace std;
int n,k,sum,a[1000005];
bool check(int s,int e)
{
	int x=a[s];
	for(int i=s+1;i<=e;i++)
	{
		x^=a[i];
	}
	if(x==k)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int start=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=start;j<=i;j++)
		{
			if(check(j,i))
			{
				
				sum++;
				start=i+1;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}