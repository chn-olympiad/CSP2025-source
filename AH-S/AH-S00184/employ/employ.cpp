#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,ans=1;
	string s;
	cin>>n>>s;
	if(s.find("0")==string::npos)
	{
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	else cout<<0;
}
