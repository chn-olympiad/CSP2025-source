#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,b,c,k,a[200010];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//cout<<0<<endl;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			c++;
		}
		if(a[i]==1)
		{
			b++;
		}
	}
	if(k==0)
	{
		cout<<c<<endl;;
	}
	else
	{
		cout<<b<<endl;
	}
	return 0;
}
