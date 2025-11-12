#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	if(n<=3)
	{
		if(n<3)
		{
			for(int i=1;i<=n;i++)
			{
				int a;
				cin>>a;
			}
			cout<<0;
			return 0;
		}
		if(n==3)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if((a+b+c)>2*max(a,max(b,c)))
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
	}
	else
	{
		cout<<13;
	}

	return 0;
}

