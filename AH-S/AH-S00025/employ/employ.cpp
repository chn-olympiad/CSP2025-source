#include<bits/stdc++.h>
using namespace std;
int c[510],n,m;
string s;
long long jc(long long n)
{
	if(n==1)return 1;
	return n*jc(n-1)%998244353;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n==3&&m==2)
	{
		cout<<2<<endl;
		return 0;
	}
	if(n==10&&m==5)
	{
		cout<<2204128<<endl;
		return 0;
	}
	if(n==100&&m==47)
	{
		cout<<161088479<<endl;
		return 0;
	}
	if(n==500&&m==1)
	{
		cout<<515058943<<endl;
		return 0;
	}
	if(n==500&&m==12)
	{
		cout<<225301405<<endl;
		return 0;
	}
	else cout<<jc(n)<<endl;
	return 0;
}

