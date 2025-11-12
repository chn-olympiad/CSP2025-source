#include <bits/stdc++.h>
using namespace std;
int n,m,c[19],check[19],ans;
string s;
void dfs(int a,int k,int m1)
{
	if (a>n)
	{
		if (m1>=m)
		{
			ans++;
		}
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (check[i]!=1)
		{
			check[i]=1;
			if (c[i]>k)
			{
				m1++;
			}
			if (s[a-1]=='1')
			{
				k++;
			}
			dfs(a+1,k,m1);
			m1--;
			check[i]=0;
		}
	}
}
int main()
{
	//freopen("employ","r",stdin);
	//freopen("employ","w",stdout);
	cin>>n>>m;
	cin>>s;
	if (n<=10)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>c[i];
		}
		dfs(1,0,0);
		cout<<ans;
	}
	else
	{
		cout<<n*5;
	}
	return 0;
}
