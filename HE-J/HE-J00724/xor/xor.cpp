#include<bits/stdc++.h>
using namespace std;
int a[100086];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0;
	if(k==0)
	{
		int js=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[js])
			{
				ans++;
				js=i+1;
				i++;
			}
			else if(a[i]==a[i+1])
			{
				ans++;
				js=i+2;
				i+=2;
			}
		}
	}
	if(k==1)
	{
		int js=0;
		for(int i=0;i<n;i++)
		{
			if(a[js]==1)
			{
				ans++;
				js++;
			}
			else if(a[i]!=a[js])
			{
				ans++;
				js=i+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
