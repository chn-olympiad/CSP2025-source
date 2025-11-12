#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,w[505];
string s;
int f(int a)
{
	int ans=1;
	for(int i=1;i<=a;i++)
	{
		ans=ans*i;
		ans%=998244353;
	}
	return ans;
}
int p(int a)
{
	int ans=1;
	for(int i=1;i<=a;i++)
	{
		ans=ans*2;
		ans%=998244353;
	}
	return ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int nn=0;
	bool A=1;
	for(int i=0;i<n;i++)
	{
		bool t=(s[i]=='1');
		A&=t;		
		int x;
		cin>>x;
		if(x!=0)nn++;
	}
	if(A)
	{
		cout<<f(n)/f(n-nn);
	}
	else 
	{
		cout<<0;
	}
	return 0;
}
