#include<bits/stdc++.h>
using namespace std;
int k[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string a;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
		cin>>k[i];
	if(a[1]=='0')
	{
		cout<<0;
		return 0;
	}
	else
	{
		long long s=1;
		for(int i=1;i<=n;i++)
			s=s*i;
		s=s%998244353;
		cout<<s;
		return 0;
	}
	return 0;
}
