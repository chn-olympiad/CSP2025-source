#include<bits/stdc++.h>
using namespace std;
long long T,n,ans,bj[100005];
struct ss{
	long long a,b,c,d;
}s[100005];
int dfs(int x,int y)
{
	long long sum=0;
	bj[y]--;
	if(x>n||bj[y]<0)
	{
		bj[y]++;
		return 0;
	}
	if(y==1)
	{
		sum+=s[x].a;
	}
	if(y==2)
	{
		sum+=s[x].b;
	}
	if(y==3)
	{
		sum+=s[x].c;
	}
	sum+=max(dfs(x+1,1),max(dfs(x+1,2),dfs(x+1,3)));
	bj[y]++;
	return sum;
}
int main() 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T); 
	while(T--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&s[i].a,&s[i].b,&s[i].c);
		}
		bj[1]=bj[2]=bj[3]=n/2;
		ans=max(dfs(1,1),max(dfs(1,2),dfs(1,3)));
		printf("%lld\n",ans);
	}
	return 0;
}
