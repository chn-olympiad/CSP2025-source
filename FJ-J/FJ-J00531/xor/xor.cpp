#include <bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ans++;
		}
	}
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cout<<ans;
	return 0;
}
