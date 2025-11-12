#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans;
struct Node{
	int f,m,l;
}a[N];
void dfs(int idx,int cnta,int cntb,int cntc,int sum)
{
	if(cnta>n/2||cntb>n/2||cntc>n/2) return ;
	if(idx==n+1)
	{
		ans=max(ans,sum);
		return ;
	}
	dfs(idx+1,cnta+1,cntb,cntc,sum+a[idx].f);
	dfs(idx+1,cnta,cntb+1,cntc,sum+a[idx].m);
	dfs(idx+1,cnta,cntb,cntc+1,sum+a[idx].l);
}
bool cmp(Node s,Node j)
{
	return s.f>j.f;
}
bool cmp2(Node s,Node j)
{
	return s.m>j.m;
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
			scanf("%d%d%d",&a[i].f,&a[i].m,&a[i].l);
		ans=0;
		if(n<=30)
		{
			dfs(1,0,0,0,0);
			printf("%d\n",ans);
		}
		else
		{
			bool flag=false,flag2=false;
			for(int i=1;i<=n;i++)
			{
				if(a[i].m!=0)
					flag=true;
				if(a[i].l!=0)
					flag2=true;
			}
			if(flag!=true&&flag2!=true)
			{
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++)
					ans+=a[i].f;
				printf("%d\n",ans);
			}
			else if(flag2!=true)
			{
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++)
					ans+=a[i].f;
				for(int i=n/2+1;i<=n;i++)
					ans+=a[i].m;
				int ans2=0;
				sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++)
					ans2+=a[i].f;
				for(int i=n/2+1;i<=n;i++)
					ans2+=a[i].m;
				printf("%d\n",max(ans,ans2));
			}
		}
	}
	return 0;
}
