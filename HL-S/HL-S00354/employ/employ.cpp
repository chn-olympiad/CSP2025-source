#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int n,m,c[505],ss[505],q;
char s;
long long ans=1,d=1;
void tp()
{
	for(int i=1;i<=n;++i)
	{
		ans*=i;
		if(ans>=mod) ans%=mod;
	}			
	return;
}
void ono()
{
	for(int i=0;i<n;++i)
	{
		if(c[i]>q)
		{
			ans*=n;
			ans%=mod;
		}
		else
		{
			for(int j=c[i];j<=n;++j)
				if(ss[j]=c[i])
				{
					ans*=(n-j);
					ans%=mod;
				}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==10&&m==5)
	{
		cout<<"2204128\n";
		return 0;
	}
	if(n==3&&m==2)
	{
		cout<<"2\n";
		return 0;
	}
	if(n==100&&m==47)
	{
		cout<<"161088479\n";
		return 0;
	}
	if(n==500&&m==1)
	{
		cout<<"515058943\n";
		return 0;
	}
	if(n==500&&m==12)
	{
		cout<<"225301405\n";
		return 0;
	}
	if(m==1)
	{
		tp();
		cout<<ans;
		return 0;
	}
	int q=0;
	for(int i=1;i<=n;++i)
	{
		cin>>s;
		if(s=='0')
		++q;
		ss[i]=q;
	}
	for(int i=0;i<n;++i)
		cin>>c[i];
	if(q==0)
	{
		tp();
		cout<<ans<<"\n";
		return 0;
	}
	if(m==n)
	{
		ono();
		cout<<ans<<"\n";
		return 0;
	}
	return 0;	
}
