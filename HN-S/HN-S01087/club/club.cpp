#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100010][4];
int sp[100010];
int rec[100010];
int maxn=-1;
void dfs(int ans,int club,int num)
{
	maxn=max(maxn,ans);
	if(num>n/2)
	{
		if(club==3)return ;
		num=0;
		club++;
		dfs(ans,club,num);
	}
	for(int i=1;i<=n;i++)
	{
		if(!rec[i])
		{
			rec[i]=1;
			dfs(ans+a[i][club],club,num++);
			rec[i]=0;
			dfs(ans-a[i][club],club,num--);
		}
		
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0)flag=0;
			sp[i]=a[i][1];
		}
		if(flag)
		{
			sort(sp+1,sp+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				maxn+=sp[i];
			}
			cout<<maxn<<endl;
			continue;
		}
		dfs(0,1,0);
		cout<<maxn<<endl;
		for(int i=1;i<=n;i++)
		{
			rec[i]=0;
			sp[i]=0;
			for(int j=1;j<=3;j++)
			{
				a[i][j]=0;
			}
		} 
		maxn=-1;
	}
	return 0;
} 
