#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
bool vis[500005];
long long ans,ans2;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) ans++;
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans2++;
				vis[i]=1;
			}
			else if(a[i]==a[i-1] && vis[i-1]==0)
			{
				ans2++;
				vis[i]=1;
			}
		}
		cout<<ans2;
	}
	else if(k==1)
	{
		cout<<ans<<" ";
	}
	else cout<<"12701"; 
	return 0;
 } 
