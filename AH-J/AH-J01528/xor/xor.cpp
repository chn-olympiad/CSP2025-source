#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[211111],ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k) ans++;
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0&&a[i+1]==a[i])
			{
				i++;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}


