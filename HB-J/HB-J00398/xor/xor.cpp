#include <bits/stdc++.h>
using namespace std;
int n,k,a[105],flag,cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0) flag=1;
	}
	if(!flag)
	{
		if(k==0)
		{
			cout<<n/2;
		}
	}
	else
	{
		if(k==0)
		{
			for(int i=0;i<n;i++)
			{
				if(a[i]==0) cnt++;
				if(a[i]==1&&a[i+1]==1)
				{
					cnt++;
					i++;
				}
			}
			cout<<cnt;
		}
		if(k==1)
		{
			for(int i=0;i<n;i++)
			{
				if(a[i]==1) cnt++;
				else if(a[i]==1&&a[i+1]==0||a[i]==0&&a[i+1]==1)
				{
					cnt++;
					i++;
				}
			}
			cout<<cnt;
		}
	}
	return 0;
}
