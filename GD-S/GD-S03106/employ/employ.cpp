#include<bits/stdc++.h>
#define ll long long
#define N 510
using namespace std;

const ll mod=998244353;
ll n,m,C[2*N][2*N],c[2*N];
bool flag;
char s[N];

int main()
{
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	C[1][0]=C[1][1]=1;
	for(int i=1;i<=N;i++) C[i][i]=1;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<i;j++)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]%=mod;
		}
	}
	flag=false;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>s[i];
		if(s[i]!='1') flag=true;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==m)
	{
		if(flag==true) 
		{
			cout<<0;
			return 0;
		}
		else
		{
			ll ans=1;
			for(int i=1;i<=n;i++)
			{
				ans=(ans%mod*i)%mod;
			}
			cout<<ans%mod;
			return 0;
		}
	}
	if(flag==false)
	{
		ll ans=1;
		for(int i=1;i<=m;i++)
		{
			ans=(ans%mod*i)%mod;
		}
		cout<<(ans*C[n][m])%mod;
		return 0;
	}
	return 0;
} 
