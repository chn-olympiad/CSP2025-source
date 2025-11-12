#include<bits/stdc++.h>
using namespace std;
int a[1000003];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >>n >>k;
	int sum0=0,sum1=0;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
		if(a[i]==0) sum0++;
		if(a[i]==1) sum1++;
	}
	if(sum1==n)
	{
		cout <<n/2;
		return 0;
	}
	else if(sum0+sum1==n)
	{
		if(k==1)
		{
			cout <<sum1;
			return 0;
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
					continue;
				}
				int chang=0;
				for(int j=i;j<=n;j++)
				{
					if(a[j]==1) chang++;
					else break;
				}
				ans=ans+chang/2;
				i=i+chang-1;
			}
			cout <<ans;
			return 0;
		}
	}
	return 0;
}
