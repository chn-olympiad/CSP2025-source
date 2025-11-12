#include <bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],f,f1,ans;
struct Aa
{
	int a,b,c;
}t1[100010];
bool cmp(Aa x,Aa y)
{
	return x.c>y.c;
}
void dfs(int cs,int s1,int s2,int s3,int myd)
{
	if(cs>n)
	{
		ans=max(ans,myd);
		return;
	}
	if(s1<n/2)
		dfs(cs+1,s1+1,s2,s3,myd+a[cs]);
	if(s2<n/2)
		dfs(cs+1,s1,s2+1,s3,myd+b[cs]);
	if(s3<n/2)
		dfs(cs+1,s1,s2,s3+1,myd+c[cs]);
}
void solve()
{
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	f=0,f1=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(b[i]!=0 or c[i]!=0)
			f=1;
		if(c[i]!=0)
			f1=1;
	}
	if(!f)
	{
		sort(a+1,a+n+1);
		for(int i=n;i>n/2;i--)
			ans+=a[i];
		printf("%d\n",ans);
		return;
	}
	if(!f1)
	{
		for(int i=1;i<=n;i++)
			t1[i].a=a[i],t1[i].b=b[i],t1[i].c=a[i]-b[i];
		sort(t1+1,t1+n+1,cmp);
		for(int i=1;i<=n/2;i++)
			ans+=t1[i].a;
		for(int i=n/2+1;i<=n;i++)
			ans+=t1[i].b;
		printf("%d\n",ans);
		return;
	}
	dfs(1,0,0,0,0);
	printf("%d\n",ans);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}