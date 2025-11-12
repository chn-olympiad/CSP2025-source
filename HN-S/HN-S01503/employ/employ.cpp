#include<bits/stdc++.h>
using namespace std;

int c[1000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
} 
