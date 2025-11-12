#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1];
	memset(a,0,sizeof(a));
	int t=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				t++;
			}
		}
		cout<<t;
		return 0;
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				t++;
			}
			if(a[i]==1 && a[i+1]==1)
			{
				t++;
				a[i]=a[i+1]=2;
			}
		}
		cout<<t;
		return 0;
	}
}
