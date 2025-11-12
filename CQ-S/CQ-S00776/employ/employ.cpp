#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],ans=1,num;
char s[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	num=n;
	cin>>s;
	for (int i=1;i<=num;i++)
	{
		cin>>c[i];
		if (c[i]==0)
		{
			n--;
		}
	}
	for (int i=1;i<=n;i++)
	{
		ans*=i;
	}
	if (n==0)
	{
		cout<<0;
	}
	else
	{
		cout<<ans%998244353;
	}
	return 0;
}
