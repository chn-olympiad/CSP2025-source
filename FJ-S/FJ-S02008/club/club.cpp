#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e5+5;

struct student
{
	ll a,b,c;
}p[maxn];

int n;
ll ans;
ll s1,s2,s3;

bool cmp(student x,student y)
{
	if(x.a==y.a)
	{
		if(x.b==y.b)  return x.c>y.c;
		return x.b>y.b;
	}
	return x.a>y.a;
}

void dfs(int g,int t1,int t2,int t3)
{
	if(g==n+1) {ans=max(ans,s1+s2+s3); return;}
	if(t1<n/2) s1+=p[g].a , dfs(g+1,t1+1,t2,t3) , s1-=p[g].a;
	if(t2<n/2) s2+=p[g].b , dfs(g+1,t1,t2+1,t3) , s2-=p[g].b;
	if(t3<n/2) s3+=p[g].c , dfs(g+1,t1,t2,t3+1) , s3-=p[g].c;
}

void work1()
{
	ans=0;
	dfs(1,0,0,0);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);
		}
		if(n<=10)  work1();  printf("%lld\n",ans);//20pts
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n/2;i++) ans+=p[i].a;//5pts
		printf("%lld\n",ans);
	}
	int g_g=0;
	return g_g; 
}
/*
1
4
4 2 1
3 2 4
5 3 4 
3 5 1
*/
