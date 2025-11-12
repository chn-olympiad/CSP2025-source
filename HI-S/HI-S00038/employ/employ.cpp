# include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
bool f;
int a[10005];
int c[10005];
bool b[10005];
void dfs(int k)
{
	if (k==n+1)
	{
		cnt ++;
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]==0)
		{
			b[i]=1;
			c[k]=i;
			dfs(k+1);
			b[i]=0;
		}
	}
}
void A()
{
	dfs(1);
	cout << cnt;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	string s="";
	cin >> s;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=0;i<n;i++)
	{
		if (s[i]!='1')  f=1;
	}
	if (f==0)
	{
		A();
		return 0;
	}
	return 0;
}
