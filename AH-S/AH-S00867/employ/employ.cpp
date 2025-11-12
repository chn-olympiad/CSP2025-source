#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],flag,fl;
long long sum=1;
string str;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='0') flag=1;
		if(str[i]=='1') fl=1;
	}
	if(flag==0||n==m) 
	{
		for(int i=m;i>=1;i--)
		{
			sum=sum*m%998244353;
		}
		cout<<m;
	}
	if(fl==0)
	{
		cout<<0;
	}
}
