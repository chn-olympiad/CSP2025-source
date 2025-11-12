#include<bits/stdc++.h>
using namespace std;
int a[510],n,m;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	bool b=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) b=false;
	}
	if(b==true)
	{
		long long ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
		cout<<ans;
	}
	return 0;
}
/*

*/
