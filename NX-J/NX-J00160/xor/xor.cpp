#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[1000010];
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
			{
				cout<<1;
				return 0;
			}
		}
		cout<<0;
	}
	if(k==1)
	{
		cout<<n-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
