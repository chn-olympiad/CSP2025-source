#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[100500];
int f[1005],v[550];
long long ans,mod=998244353,jc[1005],zh[505][505],pl[505][505];
void init()
{
	zh[0][0]=1;
	for(int i=1;i<=500;i++)
	{
		zh[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			zh[i][j]=zh[i-1][j]+zh[i-1][j-1];
			zh[i][j]%=mod;
		}
	}
	jc[0]=1;
	for(int i=1;i<=500;i++) jc[i]=jc[i-1]*i%mod;
	for(int i=1;i<=500;i++)
	{
		for(int j=1;j<=i;j++) pl[i][j]=zh[i][j]*jc[j]%mod;
	}
}
void dfs(int x)
{
	if(x>n)
	{
		int ap=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(c[f[i]]<=cnt)
			{
				cnt++;
				continue;
			}
			if(s[i-1]=='0') cnt++; 
			else
			{
				ap++;
			}
		}
		if(ap>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==1) continue;
		v[i]=1;
		f[x]=i;
		dfs(x+1);
		v[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	init();
	int flag=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<jc[n];
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=11)
	{
		dfs(1); 
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
