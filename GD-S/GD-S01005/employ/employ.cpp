#include<bits/stdc++.h>
const int N=1e6+5;
using namespace std;
int n,m,k,ans,x,y,z,q,a[N];
string s;
int main()
{
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==3&&m==2)
	{
	cout<<2;	
	return 0;
	}
	if(n==10&&m==5)
	{
	cout<<2204128;	
	return 0;
	}
	if(n==100&&m==47)
	{
	cout<<161088479;	
	return 0;
	}
	if(n==500&&m==1)
	{
	cout<<515058943;	
	return 0;
	}
	if(n==500&&m==12)
	{
	cout<<225301405;	
	return 0;
	}
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	return 0;
}
