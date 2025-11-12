#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100010],k;
long long ans;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		for(int i=0;i<m;i++)
		{
			if(s[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
		{
			ans*=(++k);
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}//🏁🏁🏁

