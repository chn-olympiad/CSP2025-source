#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+7;
int n;
int b[N][4],cnt[4],ans;
bool f1=0,f2=0,f3=0,vis[N];
struct node
{
	int x,y,z;
}a[N*3];
bool cmp(node p,node q)
{
	return p.x>q.x;
}
void dfs(int sum,int x)
{
	if(x==n+1)
	{
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]>=n/2)continue;
		cnt[i]++;
		dfs(sum+b[x][i],x+1);
		cnt[i]--;
	}
}
int main(void)
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(cnt,sizeof(cnt),0);
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>b[i][j];
				if(j==3&&b[i][j])f1=1;
				if(j==2&&b[i][j])f2=1;
				if(j==1&&b[i][j])f3=1;
			}
		}
		
		if(f1==f2&&f1==0)
		{
			int idx=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					a[(i-1)*3+j].x=b[i][j];
					a[(i-1)*3+j].y=j;
					a[(i-1)*3+j].z=i;
				}
			}
			sort(a+1,a+1+3*n,cmp);
			for(int i=1;i<=n*3;i++)
			{
				if(cnt[a[i].y]<n/2&&vis[a[i].z]==0)
				{
					ans+=a[i].x;
					cnt[a[i].y]++;
					vis[a[i].z]=1;
				}
				cout<<a[i].x<<' ';
			}
		cout<<ans<<endl;
		continue;
	}
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
