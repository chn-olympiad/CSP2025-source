#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=1e5+10;
int a[N][4],sz[4],b[N];
int n,ans,sum;
void dfs(int w)
{
	if(w==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
		if(sz[i]<n/2)
		{
			sz[i]++;
			sum+=a[w][i];
			dfs(w+1);
			sz[i]--;
			sum-=a[w][i];
		}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	{
		int pd=0;priority_queue<pii,vector<pii>,greater<pii>>A,B;
		scanf("%d",&n);sum=0;ans=0;
		memset(sz,0,sizeof sz);
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
			if(pd!=-1&&a[i][3]==0)
			{
				pd=1;
				if(a[i][2]==0)pd=2;
			}
			else pd=-1;
		}
		if(pd==-1)dfs(1);
		else if(pd==2)
		{
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n;i>=n/2;i--)ans+=b[i];
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i][1]>a[i][2])
				{
					if(A.size()<n/2)
					{
						A.push({a[i][1]-a[i][2],i});
						ans+=a[i][1];
						continue;
					}
					else
					{
						int y=A.top().second;
						if(a[i][1]+a[y][2]>a[y][1]+a[i][2])
						{
							A.pop();A.push({a[i][1]-a[i][2],i});
							ans+=a[i][1];
							B.push({0,y});
							ans+=a[y][2]-a[y][1];
						}
						else
						{
							B.push({0,i});
							ans+=a[i][2];
						}
					}
				}
				else if(a[i][1]<a[i][2])
				{
					if(B.size()<n/2)
					{
						B.push({a[i][2]-a[i][1],i});
						ans+=a[i][2];
						continue;
					}
					else
					{
						int y=B.top().second;
						if(a[i][2]+a[y][1]>a[y][2]+a[i][1])
						{
							B.pop();B.push({a[i][2]-a[i][1],i});
							ans+=a[i][2];
							A.push({0,y});
							ans+=a[y][1]-a[y][2];
						}
						else
						{
							A.push({0,i});
							ans+=a[i][1];
						}
					}
				}
				else ans+=a[i][1];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
