#include <bits/stdc++.h>
using namespace std;
int n,k;
int s[500001];
int ss[500001];
int zd=0;
void dfs(int wz,bool f,int qjs,int xk)
{
	if(wz==n+1)
	{
		if(f==false)zd=max(zd,qjs);
		return;
	}
	if(f)
	{
		if((xk^s[wz])==k)
		{
			dfs(wz+1,false,qjs+1,0);
		}
		else
		{
			dfs(wz+1,true,qjs,xk^s[wz]);
		}
		return;
	}
	if(s[wz]==k)
	{
		dfs(wz+1,false,qjs+1,0);
		return;
	}
	dfs(wz+1,true,qjs,s[wz]);
	dfs(wz+1,false,qjs,0);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int qz;
	for(int i = 1;i<=n;i++)
	{
		cin>>s[i];
		if(i==1)qz=s[i];
		else qz^=s[i];
		ss[i]=qz;
	}
	if(n>100)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = i;j<=n;j++)
			{
				for(int kk = j;kk>=i;kk--)
				{
					if(kk==j)
					{
						if(s[kk]==k)
						{
							zd++;
							i=j+1;
						}
						continue;
					}
					if(kk==1)
					{
						if(ss[j]==k)
						{
							zd++;
							i=j+1;
						}
						continue;
					}
					if((ss[kk-1]^ss[j])==k)
					{
						zd++;
						i=j+1;
					}
				}
			}
		}
		cout<<zd;
		return 0;
	}
	dfs(1,false,0,0);
	cout<<zd;
	return 0;
}
