#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],x;
long long p,mod=998244353;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		std::cin>>s[i];
		if(s[i]=='0') x=1;
	}
	for(int i=1;i<=n;i++) std::cin>>c[i];
	sort(c+1,c+n+1);
	int o=n;
	for(int i=1;i<=n;i++) if(c[i]==0) o--; else break;
	if(m==n)
	{
		if(x==1)
		{
			cout<<"0"<<endl;
			return 0;
		}
		else
		{
			p=1;
			for(long long i=1;i<=o;i++) p=p*i%mod;
			std::cout<<p<<endl;
			return 0;
		}
	}
	if(x==0)
	{
		p=1;
		for(long long i=1;i<=o;i++) p=p*i%mod;
		std::cout<<p<<endl;
		return 0;
	}
	return 0;
}