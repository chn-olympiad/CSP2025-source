#include<bits/stdc++.h>
using namespace std;
long long n,mod=998244353,s;
long long a[5005],f[5005][5005];
long long js(long long x,long long y)
{
	if(x==1||x==y-1)
	{
		return y%mod;
	}
	else if(x==y)
	{
		return 1;
	}
	if(f[x][y]!=0) return f[x][y]%mod;
	return (js(x-1,y-1)%mod+js(x,y-1)%mod)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
		sort(a+1,a+n+1);
		if((a[1]+a[2])>a[3])
		{
			s=1;
		}
		cout<<s;
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			s+=js(i,n);
			s%=mod;
		}
		cout<<s;
	}
	return 0;
}
