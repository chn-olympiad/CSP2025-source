#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+5];
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	int s=a[1];
	int i=1;
	for(;i<=n;i++)
	{	
		if(s==k)
		{
			s=a[i+1];
			i++;
			ans++;
		}
		s^=a[i];
	}
	cout<<ans;
	return 0;
}
