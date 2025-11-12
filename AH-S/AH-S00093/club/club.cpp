#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e5+5;
long long t,n,people[5],ans;
struct good_feel
{
	long long a;
	long long b;
	long long c;
}goel[MAXN];
long long love[MAXN][5];
bool cmp(good_feel x,good_feel y)
{
	return max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c));
}
long long dfs(long long x,long long find,long long sum)
{
	if(x>n)
	{
		return sum;
	}
	long long j=find,maxn=0;
	for(;j<=3;++j)
	{
		if(people[love[x][j]]<n/2) 
		{
			if(j<3) maxn=max(maxn,dfs(x,j+1,sum));
			if(love[x][j]==1) sum+=goel[x].a;
			if(love[x][j]==2) sum+=goel[x].b;
			if(love[x][j]==3) sum+=goel[x].c;
			people[love[x][j]]++;
			maxn=max(maxn,dfs(x+1,1,sum));
			if(love[x][j]==1) sum-=goel[x].a;
			if(love[x][j]==2) sum-=goel[x].b;
			if(love[x][j]==3) sum-=goel[x].c;
			people[love[x][j]]--;
		}
	}
	return maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		memset(people,0,sizeof(people));
		scanf("%lld",&n);
		for(long long i=1;i<=n;++i)
		{
			scanf("%lld%lld%lld",&goel[i].a,&goel[i].b,&goel[i].c);
		}
		sort(goel+1,goel+n+1,cmp);
		for(long long i=1;i<=n;++i)
		{
			long long a=goel[i].a,b=goel[i].b,c=goel[i].c;
			if(a>=b&&b>=c) {love[i][1]=1;love[i][2]=2;love[i][3]=3;}
			if(a>=c&&c>=b) {love[i][1]=1;love[i][2]=3;love[i][3]=2;}
			if(b>=a&&a>=c) {love[i][1]=2;love[i][2]=1;love[i][3]=3;}
			if(b>=c&&c>=a) {love[i][1]=2;love[i][2]=3;love[i][3]=1;}
			if(c>=a&&a>=b) {love[i][1]=3;love[i][2]=1;love[i][3]=2;}
			if(c>=b&&b>=a) {love[i][1]=3;love[i][2]=2;love[i][3]=1;}
		}
		ans=dfs(1,1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
/* 
 1
 4 
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 */
