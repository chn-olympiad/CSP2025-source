#include<bits/stdc++.h>
using namespace std;
const int N=550,mod=998244353;
int m,n,n0,n1,a1[N];
long long ans,ans1;
char s[N];
bool flag[N];
struct edge
{
	int i,c;
}a[N];
bool cmp(edge x,edge y)
{
	return x.c<y.c;
}
void dfs(int u,int u1,int sum,int goal)
{
	if((goal-sum)>(n1-u+1)||sum>goal)
		return;
	if(sum==goal)
	{
		ans=(ans+1ll)%(mod*1ll);
		return;
	}
	for(int i=u1+1;i<=n;i++)
	{
		if(flag[i])
		continue;
		if(a[i].c>(a1[u-1]-sum))
		{
		//	printf("->:%d\n",i);
			flag[i]=true;
			dfs(u+1,i,sum+1,goal);
			flag[i]=false;
		}
		else
		{
		//	printf("->%d\n",i);
			flag[i]=true;
			dfs(u+1,i,sum,goal);
			flag[i]=false;
		}
	}
}
int main ()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&s[i]);
		if(s[i]=='0')
		n0++;
		else
		{
			a1[++n1]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].c);
	}
	if(n1==n)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(i*1ll*ans)%(mod*1ll);
		}
		printf("%lld\n",ans);
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=m;i<=n1;i++)
	{
		ans=0;
		dfs(0,0,0,i);
		printf("%d:%lld\n",i,ans);
		for(int j=2;j<=(n-i);j++)
		{
			ans=(1ll*j*ans)%(1ll*mod);
		}
		ans1=(ans1+ans)%(1ll*mod);
	}
	printf("%lld\n",ans1);
	return 0;
}//1010我喜欢李佳诺