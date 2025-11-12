#include<bits/stdc++.h>
using namespace std;

const int N = 5010,mod = 998244353;
int n,ans,sum;
int a[N];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
	}
	sum=1;
	
	for(int i=1;i<=n-3;i++)
	{
		sum*=i;
	}
	ans/=(sum*6);
	cout<<ans;
	return 0;
}
