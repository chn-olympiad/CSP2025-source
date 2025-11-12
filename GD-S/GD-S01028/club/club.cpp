#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=1e6;
struct Node{int g[3];} s[maxn];
int t,n,ans,res,cnt[3];
priority_queue<int,vector<int>,greater<int>> qq1,qq2;
void check()
{
	while(qq1.size()>n/2)
		res-=qq1.top(),qq1.pop();
	while(qq2.size()>n/2)
		res-=qq2.top(),qq2.pop();
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&s[i].g[0],&s[i].g[1],&s[i].g[2]);
		ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)
		{
			int id=-1;
			for(int j=0;j<3;j++)
				if(cnt[j]<n/2&&(id==-1||s[i].g[j]>s[i].g[id]))id=j;
			ans+=s[i].g[id];
			cnt[id]++;
		}
		for(int i=0;i<3;i++)
		{
			res=0;
			while(!qq1.empty())qq1.pop();
			while(!qq2.empty())qq2.pop();
			for(int j=1;j<=n;j++)
			{
				int tmp=0;
				for(int k=0;k<3;k++)
					if(i!=k)tmp=max(tmp,s[j].g[k]);
				if(s[j].g[i]>=tmp)
				{
					res+=s[j].g[i];
					qq1.push(s[j].g[i]-tmp);
				}
				else
				{
					res+=tmp;
					qq2.push(tmp-s[j].g[i]);
				}
				check();
			}
			ans=max(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}
