#include <bits/stdc++.h>
using namespace std;
int n,k,a[1005],m[1005][1005],temp,ans,cnt;
bool flag[1005];
bool check(int ll,int rr)
{
	for(int i=ll;i<=rr;i++)
	{
		if(flag[i]==false) return false;
	}
	return true;
}
void dfs(int l,int r,int tans)
{
	if(!check(l,r) or m[l][r]!=k) return ;
	for(int i=l;i<=r;i++)
	{
		flag[i]=false;
	}
	tans++;
	ans=max(ans,tans);
	for(int i=r+1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			dfs(i,j,tans);
			for(int k=i;k<=j;k++)
			{
				flag[i]=true;
			}
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				m[i][j]=a[i];
				for(int k=i+1;k<=j;k++)
				{
					m[i][j]=m[i][j]^a[k];
				}
				if(m[i][j]==k) cnt++;
			}
			else
			{
				m[i][j]=a[i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			memset(flag,true,sizeof(flag));
			dfs(i,j,0);
		}
	}
	cout<<ans;
	return 0;
}
