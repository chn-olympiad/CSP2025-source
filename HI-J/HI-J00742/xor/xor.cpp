#include <bits/stdc++.h>
using namespace std;
long long n,k,a[100009],ans,anss[2];
bool flG;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) 	anss[1]++;
		else if(a[i]==0)	anss[0]++;
		else flG=1;
	}
	if(flG==0)
	{
		if(anss[1]==n) 	cout<<n;
		else 	cout<<anss[k];
		return 0;
	}
	else 
	{
		for(int i=1;i<=n;i++)
		{
			long long ls=a[i];
			if(a[i]==k)
			{
				ans++;
				continue;
			}
			for(int j=i+1;j<=n;j++) 
			{
				ls=(ls^a[j]);
				if(ls==k) 
				{
					ans++;
					i=j;
					break;
				}
			}
		}
		cout<<ans;
	}
	return 0;
} 
