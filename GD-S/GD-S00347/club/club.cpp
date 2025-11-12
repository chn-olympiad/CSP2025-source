#include<bits/stdc++.h>
using namespace std;
int n,a[100010][10],ans,b[100010];
int mem[210][210][210];
void dfs(int now,int sum,int a1,int a2,int a3)
{
	if(now==n+1)
	{
		ans=max(ans,sum);
		return ;
	}
	if(sum<mem[a1][a2][a3]) return ;
	mem[a1][a2][a3]=sum;
	if(sum+b[n]-b[now-1]<ans) return ;
	if(a1>0) dfs(now+1,sum+a[now][1],a1-1,a2,a3);
	if(a2>0) dfs(now+1,sum+a[now][2],a1,a2-1,a3);
	if(a3>0) dfs(now+1,sum+a[now][3],a1,a2,a3-1);
}
void dfs2(int now,int sum,int a1,int a2)
{
	if(now==n+1)
	{
		ans=max(ans,sum);
		return ;
	}
	if(sum+b[n]-b[now-1]<ans) return ;
	if(a1>0) dfs2(now+1,sum+a[now][1],a1-1,a2);
	if(a2>0) dfs2(now+1,sum+a[now][2],a1,a2-1);
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		bool bbb=true,bb=true;
		for(int i=1;i<=n;i++)
		{
			int Max=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(j==2 && a[i][j]!=0) bb=false;
				if(j==3 && a[i][j]!=0) bb=bbb=false;
				Max=max(Max,a[i][j]);
			}
			b[i]=b[i-1]+Max;
		}
		memset(mem,-1,sizeof(mem));
		if(!bb && !bbb)
		{
			dfs(1,0,n/2,n/2,n/2);
		}
		else if(bbb)
		{
			dfs2(1,0,n/2,n/2);
		}
		else
		{
			vector<int> vt;
			for(int i=1;i<=n;i++) vt.push_back(a[i][1]);
			sort(vt.begin(),vt.end(),cmp);
			for(int i=0;i<n/2;i++) ans+=vt[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
