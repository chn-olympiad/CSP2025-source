#include<bits/stdc++.h>
using namespace std;
int xz[114514][5];
int t,n,d[3],vis[114514],maxn=-1;
int wepon(){
	
}
void dfs(int k,int man,int now,int no,int sum)//sum总数,k第几个，man最多多少个，now现在几个人，no第几个部门 
{
	
	if(now>=man&&no==3)
	{
		maxn=max(maxn,sum);
		return;
	}
	if(no>3)
	{
		return ;
	}
	if(now>man)
	{
		return ;
	}
	if(k>n)
	{
		return ;
	}
	if(now==man)
	{
		dfs(k,man/2,0,no+1,sum);
		cout<<sum<<" ";
	}
	dfs(k+1,man,now+1,no,sum+xz[k][no]); 
	dfs(k+1,man,1,no+1,sum+xz[k][no+1]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int lll=1;lll<=t;lll++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				cin>>xz[i][j];
		}
		dfs(1,n/2,0,1,0);
		cout<<maxn<<endl;
		wepon()
	}
	return 0; 
}
