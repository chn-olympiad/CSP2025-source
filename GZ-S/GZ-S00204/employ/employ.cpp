//GZ-S00204 贵阳市第一中学 曹玄憬
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[506],b[506],ans=1;
const int mod=998244353;
int main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans=ans%mod;
	}
	cout<<ans;
	return 0;	
} 
