#include<bits/stdc++.h>

using namespace std;
int t;
int n;
int a[100005][3];
int m[3];
int c1[100005],x1=0,c2[100005],x2=0,ans=0;
int x(int cnt,int u)
{
	if(u>n)
	{
		return cnt;
	}
	int ans=0;
	for(int i=0;i<=2;i++)
	{
		if(m[i]==n/2)
		{
			continue;
		}
		m[i]++;
		ans=max(ans,x(cnt+a[u][i],u+1));
		m[i]--;
	}
	return ans;
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
		{
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		}
		if(n<=10)
		{
			printf("%d\n",x(0,1));
		}
		else
		{
			ans=0;
			x1=0;
			x2=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i][0]>a[i][1])
				{
					ans+=a[i][0];
					x1++;
					c1[x1]=a[i][0]-a[i][1];
				}
				else
				{
					ans+=a[i][1];
					x2++;
					c2[x2]=a[i][1]-a[i][0];
				}
			}
			if(x1>n/2)
			{
				sort(c1+1,c1+x1+1);
				for(int i=1;i<=x1-n/2;i++)
				{
					ans-=c1[i];
				}
			}
			else if(x1<n/2)
			{
				sort(c2+1,c2+x2+1);
				for(int i=1;i<=x2-n/2;i++)
				{
					ans-=c2[i];
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
