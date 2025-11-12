#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=510;
int y;
int n,m;
int s[N];
int c[N];
int a[N];
int ans=0;
int w[N];
void dfs(int j)
{
	if(j>n)
	{
		
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	int f=0;
	y=n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin >> x;
		s[i]=x-'0';
		if(s[i]==1) f++;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
		if(c[i]==0) y--;
	}
	if(m>y)
	{
		cout << 0;
		return 0;
	}
	a[0]=1;
	for(int i=1;i<=n;i++)  a[i]=(a[i-1]*i)%mod;
	if(f==n)
	{
		cout << a[n];
		return 0;
	}
	
	return 0;
}
