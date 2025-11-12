#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=510,N=262144,K=20,mod=998244353;
ll n,m,c[M],f[N][K],t,sz,s,p,ff[M][M];char ch;bool d[M];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(register ll i=1;i<=n;i++)
	{
		cin>>ch;
		d[i]=(ch=='1');
		if(!d[i])p=-1;
	}
	for(register ll i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=18)
	{
		t=(1<<n)-1;
		f[0][0]=1;
		for(register ll i=0;i<t;i++)
		{
			sz=0;
			for(register ll j=0;j<n;j++)
				if((i>>j)&1)++sz; 
			for(register ll j=0;j<n;j++)
			{
				if(!f[i][j])continue;
				for(register ll k=0;k<n;k++)
				{
					if((i>>k)&1)continue;
					if(sz-j>=c[k+1]||!d[sz+1])f[i|(1<<k)][j]=(f[i|(1<<k)][j]+f[i][j])%mod;
					else f[i|(1<<k)][j+1]=(f[i|(1<<k)][j+1]+f[i][j])%mod;
				}
			}
		}
		for(register ll i=m;i<=n;i++)
			s=(s+f[t][i])%mod;
		cout<<s;
		return 0;
	}
	else if(m==n)
	{
		if(p==-1)cout<<0,exit(0);
		for(register ll i=1;i<=n;i++)
			if(!c[i])cout<<0,exit(0);
		s=1;
		for(register ll i=1;i<=n;i++)s=s*i%mod;
		cout<<s;
		return 0;
	}
//	else if(p!=-1)
//	{
//		ff[0][0]=1;
//		for(register ll i=1;i<=n;i++)
//			for(register ll j=0;j<=p;j++)
//			{
//				
//			}
//	}
	cout<<0;
	return 0;
}
