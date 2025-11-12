//GZ-S00069 毕节东辰实验学校 刘顶峰 
#include<iostream>
#include<vector>
#include<string.h> 
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
ll a[1008611]={0};
ll b[1008611]={0};
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n=0,m=0;
	ll k=0,p=0;
	ll ans=1;
	cin>>n>>m;
	p=n;
	k=n-m;
	for(int j=1;j<=n;j++)
	{
		scanf("%1lld",&a[j]);
	}
	for(int j=1;j<=n;j++)
	{
		cin>>b[j];
		if(b[j]==0)
		{
			p--;
		}
	}
	if(p<m)
	{
		printf("0");
		return 0;
	}
	for(ll j=1;j<=m;j++)
	{
		ans=ans*p%998244353;
		p--;
	}
	for(ll j=m+1;j<=n;j++)
	{
		ans=ans*k%998244353;
		k--;
	}
	printf("%lld",ans);
	return 0;
}
