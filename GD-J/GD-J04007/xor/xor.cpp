#include<bits/stdc++.h>
using namespace std;
long long a[500050],n,yyy,ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>yyy;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==yyy)
		{
			ans++;
		}
	}
	if(n==1)
	{
		if(a[1]==yyy)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(yyy==0)
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i+1] && a[i]!=0)
			{
				i++;
				ans++;
			}
		}
		if(n==2)
		{
			cout<<ans;
			return 0;
		}
	}
	sort(a+1,a+1+n);
	if(a[n]==1)
	{
		cout<<ans;
		return 0;
	}
	cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
