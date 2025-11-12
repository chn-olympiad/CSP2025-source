#include<bits/stdc++.h>
using namespace std;
long long M = 998244353;
int main()
{
	long long ans=1;
	freopen("employ.in","r",stdin);
	freopen("employ,out","w",stdout);
	int m , n ,p[507],k;
	char s[507];
	cin>>n>>m;
	for(int i = 1 ; i<=n ; i++)
	{
		cin>>s[i];
		if(s[i])	k++;
	}
	if(m>k)	{cout<<0;return 0;}	
	for(int i = 1 ; i<=n ; i++)
		cin>>p[i];
	while(n--)
	{
		ans=ans*(n+1)%998244353;
	}
	cout<<ans;
	return 0;
}