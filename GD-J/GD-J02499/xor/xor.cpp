#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x==k)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
