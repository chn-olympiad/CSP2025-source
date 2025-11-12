#include<bits/stdc++.h>
using namespace std;
long long int cnt=0;
long long int n,m;
long long int vis[101001],cho[100101];
void choose(long long int x)
{
	if(x==n)
	{
		cnt++;
	}
	else
	{
		for(long long int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				vis[i]=1;
				cho[x]=i;
				choose(x+1);
				vis[i]=0;
			}
		} 
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(vis,0,sizeof(vis));
	string h;
	cin>>n>>m;
	choose(0);
	cin>>h;
	if(m==1)
	{
		for(long long int i=0;i<h.size();i++)
		{
			if(h[i]=='1')
			{
				cout<<cnt;
				return 0;
			}
		}
		cout<<0;
	}
	else
	{
		if(m==n)
		{
			for(long long int i=0;i<h.size();i++)
			{
				if(h[i]=='0')
				{
					cout<<0;
					return 0;
				}
			}
			cout<<cnt;
		}
		else
		{
			for(long long int i=0;i<h.size();i++)
			{
				if(h[i]=='0')
				{
					cout<<0;
					return 0;
				}
			}
			cout<<cnt;
		}
	}
}
