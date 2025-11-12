#include <bits/stdc++.h>
using namespace std;
int n,m;
int num,ans;
string s[505];
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x=n;
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]=='0')
			{
				num+=n;
				continue;
			}
			else
			{
				if(c[i]<num)
				{
					x--;
				}
			}
		}
		if(x>=m)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
