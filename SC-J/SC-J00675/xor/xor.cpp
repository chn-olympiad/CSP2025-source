#include<bits/stdc++.h>
using namespace std;
int s[25][1005];
int sss[1005];
int st[1005];
int cnt=0;
int k=1;
int mm;
void dfs(int x,int y)
{
	cnt=0;
	k=1;
	int xx=x;
	if(xx==0)
	{
		return ;
	}
	if(xx=1)
	{
		s[y][cnt]=1;
		return ;
	}
	while(xx!=1)
	{
		xx/=2;
		cnt+=1;
		k*=2;
	}
	if(xx==1)
	{
		s[y][cnt]=1;
	}
	sss[y]=max(k,sss[y]);
	dfs(x-k,y);
}
void yihuo(int xx,int yy)
{
	int aaa=1;
	 mm=0;
	for(int i=1;i<=max(sss[xx],sss[yy]);i++)
	{
		if(s[xx][i]!=s[yy][i])
		{
			st[i]=1;
		}
		else st[i]=0;
		mm+=1;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	dfs(m,n+1);
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int yy;
		cin>>yy;
		dfs(yy,i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
//			int flag=0;
			ans=0;
			yihuo(i,j);
			for(int i=1;i<=max(mm,sss[n+1]);i++)
			{
				if(st[i]!=s[n+1][i])
				{					
					ans=-1;
					break;
				}
			}
			if(ans!=-1)
			{
				ans+=1; 
			}
		}
	} 
	cout<<ans;
	
}
 