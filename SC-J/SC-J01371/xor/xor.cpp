#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,k,ans;
int a[500050];
int main()
{
	freopen("r","xor.in",stdin);
	freopen("w","xor.out",stdout);
	int i;
	cin>>n>>k;
	if(k!=1&&k!=0)
	{
		cout<<0;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}