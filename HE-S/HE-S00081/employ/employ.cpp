#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m,c[N];
string s;
long long a1=1;
long long jie(long long x)
{
	if(x==a1)
	{
		return a1;
	}
	return x*jie(x-a1)%mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool oka=true;
	int cnb=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			oka=false;
		}
		else
		{
			cnb++;
		}
	}
	if(oka)
	{
		long long aa=jie(n)%mod;
		cout<<aa;
	}
	else 
	{
		if(m>cnb)
		{
			cout<<0;
		}
		else
		{
			
		}
	}
	return 0;
 } 
