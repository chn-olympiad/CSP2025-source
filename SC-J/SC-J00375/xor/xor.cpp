#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],cnt1;
bool flaga=0,flagb=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flaga=1;
		}
		if(a[i]>1)
		{
			flagb=1;
		}
		if(a[i]==1)
		{
			cnt1++;
		}
	}
	if(flaga==0)
	{
		cout<<n/2;
		return 0;
	}
	if(flagb==0)
	{
		if(cnt1%2==1)
		{
			if(k==1)
			{
				cout<<n;
				return 0;
			}
			else
			{
				cout<<n-1;
				return 0;
			}
		}
		else
		{
			if(k==0)
			{
				cout<<n;
				return 0;
			}
			else
			{
				cout<<n-1;
				return 0;
			}
		}
	}
	else
	{
		cout<<n/2;
		return 0; 
	}
	return 0; 
}