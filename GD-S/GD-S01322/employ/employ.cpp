#include<iostream>
#include<cstdio> 
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int a[505]={};
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long ans=1,da=998244353;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		ans*=i;
		ans%=da;
		//cout<<ans<<" ";
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
