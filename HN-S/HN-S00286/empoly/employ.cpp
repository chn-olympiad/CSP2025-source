#include<bits/stdc++.h>
using namespace std;
long long n,m=1;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int r=n,k;
	string f;
	cin>>f;
	while(r--)
	{
		cin>>k;
		if((k==0)&&(m>1))
		{
			n--;
		}
	}
	for(int i=2;i<=n;i++)
	{
		m=(m*n)%998244353;
	}
	cout<<m;
	return 0;
}
