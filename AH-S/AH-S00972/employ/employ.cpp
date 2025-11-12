#include<bits/stdc++.h>
using namespace std;
int c[505],x[505];
long long f(int x)
{
	if(x==0)
		return 1;
	long long ans=1;
	for(int i=x;i>=2;i--)
	{
		ans*=i;
		if(ans*i>998244353)
			ans=ans%998244353;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int p=0,q=0,siz=a.size();
	for(int i=0;i<siz;i++)
	{
		if(a[i]=='0')
			q++;
		else
			p++;
	}
	if(q==siz)
		cout<<0;
	else if(p==siz)
	{
		cout<<f(n);
	}
	else if(m==1)
	{
		cout<<f(n);
	}
	return 0;
}
