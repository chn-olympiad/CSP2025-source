#include<bits/stdc++.h>
using namespace std;
int cmp(int l,int r)
{
	int k=l|r;
	int o=l&r;
	return k-o;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int ans=0;
	long long a[500001]={0};
	bool b[500001]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==k&&b[i]==0)
		{
			ans++;
			b[i]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int temp=a[i];
			if(b[i]==1)
			{
				continue;
			}
			for(int k=i+1;k<=j;k++)
			{
				temp=cmp(temp,a[k]);
				if(b[k]==1)
				{
					continue;
				}
			}
			if(temp==k)
			{
				ans++;
				for(int k=i;k<j;k++)
				{
					b[k]=1;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
