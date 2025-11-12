#include<bits/stdc++.h>
using namespace std;
long long a[600000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int y=0,z=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			y++;
		}
		if(a[i]==0)
		{
			z++;
		}
	}
	int ans;
	if(k==1)
	{
		cout<<y;
	}
	else if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1&&a[i+1]==1)
			{
				z++;
				i++;
			}
		}
		cout<<z;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}