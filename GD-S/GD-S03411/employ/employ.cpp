#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
bool pA=1;
int n,m,c[505];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(s[i-1]!='1') pA=0;
	}
	if(n==m)
	{
		bool p=1;
		int l=1,k=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0') 
			{
				p=0;
				break;
			}
		}
		if(p==0) cout<<0;
		else
		{
			long long l=1;
			for(long long i=1;i<=n;i++)
			{
				l=(l*i)%mod;
			}
			cout<<l<<endl;
		}
		return 0;
	}
	if(pA==1)
	{
		long long l=1;
		for(long long i=1;i<=n;i++)
		{
			l=(l*i)%mod;
		}
		cout<<l<<endl;
	}
	return 0;
}

