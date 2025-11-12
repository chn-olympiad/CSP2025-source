#include <bits/stdc++.h>
using namespace std;
int n,m;
string a;
int c[505];
int b[505];
long long ans;
void dfs(int where,int tt,int sum)
{
	if(n-(tt+sum)+sum < m)
	{
		return;
	}
	if(where+1 == a.size())
	{
		if(sum < m)return;
		ans++;
		ans %= 998244353;
		return;
	}
	for(int i = 1;i<=n;i++)
	{
		if(tt >= c[i])
		{
			b[i] = 2;
		}
		if(tt < c[i] && b[i] == 2)
		{
			b[i] = 0;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		if(b[i] == 0)
		{
			if(a[where] == '1')
			{
				b[i] = 1;
				dfs(where+1,tt+1,sum);
				b[i] = 0;
			}
			else
			{
				dfs(where+1,tt,sum+1); 
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cin>>a;
	for(int i = 1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
} 
/*
5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
