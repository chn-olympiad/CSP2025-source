#include<iostream>
#include<bits/stdc++.h>
using namespace std;	
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int long long n,sum=1,m;
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		sum=sum*i;
	}
	n=998244353;
	cout<<(sum%998244353)
	
}
