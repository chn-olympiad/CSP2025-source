#include <bits/stdc++.h>
using namespace std;

const int N=2*1e5+1;
int n,k,d[N],ans;

int main()
{
	freopen("xor.in","cin",stdin);
	freopen("xor.out","cin",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		if(d[i]==k)
		{
			ans++;
		}
	}
	if(k==1)
	{
		cout<<ans;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		if(d[i]==1&&d[i+1]==1)
		{
			ans++;
			i++;
		}
	}
	cout<<ans;
	return 0;
}