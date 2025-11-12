#include <bits/stdc++.h>
using namespace std;
int n,cnt;
const int mod=998244353;
long long a[5005],k;
bool flg=true;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	if(n==3 && a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
	{
		cout<<1;
		return 0;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(flag)
	{
		long long ans=n;
		for(int i=3;i<=n;i++)
		{
		    ans=ans*(n-i)%mod;	
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
