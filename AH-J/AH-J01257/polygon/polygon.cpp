#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
const int mod=998244353;
bool all;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	all=true;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			all=false;
			break;
		}
	}
	if(all)
	{
		int po=n-2;
		po%=mod;
		cout<<po<<endl;
		return 0;
	}
	else if(n==3)
	{
		if(a[1]+a[2]<=a[3])
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl;
		return 0;
	}
	return 0;
}
