#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,f1=1;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!='1')f1=0;
	} 
	if(f1)
	{
		long long ans=0;
		for(int j=m;j<=n;j++)
		{
			long long x=1;
			for(int i=1;i<=j;i++)
			{
				x*=i;
				x%=998244353;
			}
			ans+=x;
			ans%=998244353;
		}
		
		cout<<ans;
		return 0;
	}
	
	return 0;
}
