#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500009];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==m)
			ans++;
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==m)
			ans++;
			else
			{
				if(a[i]==1 && a[i+1]==1)
				{
					ans++;
					i++;
				}
				
			}
		}
		cout<<ans;
	}
	
	
	fclose(stdin);fclose(stdout);
	return 0;
}
