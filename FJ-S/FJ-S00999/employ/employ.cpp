#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string str;
	cin>>str;
	str="0"+str;
	int c[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int jc=1;
	for(int i=1;i<=n;i++)
	{
		jc*=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[j]+=c[i];
			c[i]=c[j]-c[i];
			c[i]=c[i]=c[j];
		}
	}
	return 0;
}
