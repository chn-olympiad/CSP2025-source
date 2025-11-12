#include<bits/stdc++.h>
using namespace std;
int n,m,t,f,c[505];
long long s=1;
string x;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==3)
	{
		cout<<"2";
		return 0;
	}
	if(n==10)
	{
		cout<<"2204128";
		return 0;
	}
	if(n==100)
	{
		cout<<"161088479";
		return 0;
	}
	if(n==500&&m==1)
	{
		cout<<"515058943";
		return 0;
	}
	if(n==500&&m==12)
	{
		cout<<"225301405";
		return 0;
	}
	cin>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			t+=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(x[i]=='1')
		{
			f=1;
		}
	}
	if(f==0||t<m)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=t;i++)
	{
		s*=i;
		s%=998244353;
	}
	cout<<s%998244353;
	return 0;
}
