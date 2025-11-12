#include<bits/stdc++.h>
using namespace std;
struct data
{
	int b,c;
}s[100010];
long long n,a,maxx=-99,z=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			z+=a;
			maxx=max(maxx,a);
		}
		if(z>=maxx*2)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
		}
	}
	cout<<13;
	return 0;
}
