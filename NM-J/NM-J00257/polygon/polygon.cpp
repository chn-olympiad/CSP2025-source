#include<bits/stdc++.h>
using namespace std;
int a[5100],n;
long long f(int k,int lt,int sm,int mx)
{
	int i;
	long long ans=0;
	if(k>2)
	{
		ans=sm>mx*2?1:0;
	}
	for(i=lt+1;i<=n;i++)
	{
		ans=(ans+f(k+1,i,sm+a[i],max(mx,a[i])))%998244353;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,b=0;
	long long as=1;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),b=max(b,a[i]);
	if(b>1) cout<<f(1,0,0,0);
	else
	{
		for(i=1;i<=n;i++) as=(as*2)%998244353;
		as=(as+998244353-1-n*n)%998244353;
		cout<<as;
	}
	return 0;
}
