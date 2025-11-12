#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool p=0;
	for(int i=0;i<n;i++) 
	{
		cin>>s[i];
		if(s[i]==1) p=1;
	}
	for(int i=1,c;i<=n;i++) cin>>c;
	if(!p) cout<<0;
	else
	{
		long long ans=1;
		for(int i=1;i<=n;i++) ans*=n,ans%=998244353;
		cout<<ans;
	} 
	return 0;
}
