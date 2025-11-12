#include <bits/stdc++.h>
using namespace std;
int a[500012];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0)
		ans=n;
	else if(k==1)
	{
		int i=1;
		while(i<n)
		{
			if(a[i]^a[i+1]==k)
			{
				i+=2;
				ans++;
			}
			else if(i+2<=n&&a[i]^a[i+1]^a[i+2]==k)
			{
				i+=3;
				ans++; 
			}
			else	i++;
		}
	}
	cout<<ans;
	return 0;
}
