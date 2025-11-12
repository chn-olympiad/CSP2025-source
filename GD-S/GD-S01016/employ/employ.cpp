#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5e2+10;
int fac[N+10],inv[N+10];
int a[N];
string s;
int n,m,ans;
int ksm(int x,int k)
{
	int res=1;
	while(k)
	{
		if(k&1)
		{
			res=res*x%mod;
		}
		x=x*x%mod;
		k>>=1;
	}
	return res;
}
void init()
{
	fac[0]=1;
	for(int i=1;i<=N;++i)
	{
		fac[i]=fac[i-1]*i%mod;
	}
	inv[N]=ksm(fac[N],mod-2);
//	cout<<inv[N]<<"\n";
	for(int i=N-1;~i;--i)
	{
		inv[i]=inv[i+1]*(i+1)%mod;
	}
//	cout<<inv[0];
}
int C(int n,int m)// n>m
{
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int A(int n,int m)// n>m
{
	return fac[n]*inv[n-m]%mod;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	init();
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		for(int i=0;i<n;++i)
		{
			if(s[i]=='0'||a[i+1]==0)
			{
				cout<<"0\n";
				return 0;
			}
		}
		cout<<fac[n]<<"\n";
		return 0;
	}
	if(m==1)
	{
		int k=n;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='1')
			{
				k=i;
				break;
			}
		}
		if(k==n)
		{
			cout<<"0\n";
			return 0;
		}
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			cnt+=(a[i]>k);
		}
		cout<<cnt*A(n-1,k)%mod*fac[n-k-1]%mod<<"\n";
		return 0;
	}
	bool flag=1;
	for(int i=0;i<n;++i)
	{
		if(s[i]=='0')
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
//		161088479
//		cout<<"YES\n";
		cout<<fac[n]<<"\n";
		return 0;
	}
	cout<<"0\n";
}
