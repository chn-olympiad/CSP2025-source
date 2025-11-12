#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct fen
{
	int num,id;	
};
fen a[4][100005];
int vis[100005],cnt[5],output,n;
vector<fen>tong[4]; 
bool cmp1(fen a,fen b)
{
	if(a.num==b.num)return a.id<b.id;
	return a.num>b.num;
}
bool cmp2(int a,int b)
{
	return a>b;
}
void dfs(int k,int ans)
{
	if(k>n)
	{
		output=max(output,ans);
		return;
	}
	if(cnt[1]<n/2)
	{
		cnt[1]++;
		dfs(k+1,ans+a[1][k].num);
		cnt[1]--;
	}
	if(cnt[2]<n/2)
	{
		cnt[2]++;
		dfs(k+1,ans+a[2][k].num);
		cnt[2]--;
	}
	if(cnt[3]<n/2)
	{
		cnt[3]++;
		dfs(k+1,ans+a[3][k].num);
		cnt[3]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof a);
		memset(vis,0,sizeof vis);
		tong[1].clear();
		tong[2].clear();
		tong[3].clear();
		output=0;
		cin>>n;
		bool f2=0,f3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i].num>>a[2][i].num>>a[3][i].num;
			if(a[2][i].num)f2=1;
			if(a[3][i].num)f3=1;
		}
		if(n<=30)
		{
			dfs(1,0);
			cout<<output<<"\n";
			continue;
		}
		if(!f2&&!f3)
		{
			sort(a[1]+1,a[1]+n+1,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[1][i].num;
			cout<<ans;
			continue;
		}
		if(!f3)
		{
			for(int i=1;i<=n;i++)
			{
				a[3][i]=a[1][i];
			}
			sort(a[2]+1,a[2]+n+1,cmp1);
			sort(a[2]+1,a[2]+n+1,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[1][i].num;
				vis[a[1][i].id]=1;
			}
			for(int i=1;i<=n/2;i++)
			{
				if(vis[a[2][i].id]==1)
				{
					int t1=a[2][i].id;
					if(a[2][i].num>a[3][t1].num)
					{
						vis[t1]=2;
						ans-=a[3][t1].num;
						ans+=a[2][i].num;
					}
				}
			}
			cout<<ans;
		}
	 } 
	return 0;
 } 
