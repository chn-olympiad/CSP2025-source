#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0,num=0;
string s,p2=0;
int c1=0;
vector<int>c;
vector<int>p3
vector<vector<int>>p;
vector<vector<int>> building;
int build()
{
	int m1;
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			m1=p[i];
			p[i]=p[j];
			p[j]=m1;
			for(int k=1;k<=n;k++)
			{
				num++;
				p[k][num]=i;
			}
		}
	}
	
}
int solve()
{
	build();
	for(int j=1;j<=num;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(c1<=c[i])
			{
				if(p[i][j]==1)
				{
					ans++;
				}
				else
				{
					c1++;
				}
			}
			else
			{
				c1++;
			}
		}
	}
	return ans%998244353;
}
int main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>> n >> m;
	cin>> s;
	for(int i=1;i<=n;i++)
	{
		cin>> c[i];
	}
	cout<< solve() <<endl;
	
	return  0;
}
