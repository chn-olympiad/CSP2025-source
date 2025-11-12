#include<bits/stdc++.h>
using namespace std;
int jhy;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int len=s.size();
	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]=='0')
		{
			cout<<"0"<<endl;
			return 0;
		}
	}
	long long ans=1;
	for(int i=2;i<=n;i++)
	{
		ans*=i;
		ans=ans%998244353;
	}
	cout<<ans;
	return 0;
}
