#include<bits/stdc++.h>
using namespace std;
int n,m,p=0;
long long ans=1;
string s;
int main() 
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]!='1')
		{
			p=1;
		}
	}
	if(p==0)
	{
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%998244353;
		}	
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
}