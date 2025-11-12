#include<bits/stdc++.h>
using namespace std;
int a[100010][5];
int q[100010],tot=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)
	{
		memset(q,0,sizeof(q));
		tot=0;
		int n;
		scanf("%d",&n);
		int sum=0;
		int t[5]={0,0,0,0,0};
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int mx=max(max(a[i][1],a[i][2]),a[i][3]);
			sum+=mx;
			if (mx==a[i][1])t[1]++;
			else if (mx==a[i][2])t[2]++;
			else t[3]++;
		}
		if (t[1]>n/2)
		{
			for (int i=1;i<=n;i++)
			{
				int mx=max(max(a[i][1],a[i][2]),a[i][3]);
				if (mx==a[i][1])
				{
					int mi=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
					q[++tot]=mi;
				}
			}
			sort(q+1,q+1+tot);
			for (int i=1;i<=t[1]-n/2;i++)
			{
				sum-=q[i];
			}
		}
		else if (t[2]>n/2)
		{
			for (int i=1;i<=n;i++)
			{
				int mx=max(max(a[i][1],a[i][2]),a[i][3]);
				if (mx==a[i][2])
				{
					int mi=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
					q[++tot]=mi;
				}
			}
			sort(q+1,q+1+tot);
			for (int i=1;i<=t[2]-n/2;i++)
			{
				sum-=q[i];
			}
		}
		else if (t[3]>n/2)
		{
			for (int i=1;i<=n;i++)
			{
				int mx=max(max(a[i][1],a[i][2]),a[i][3]);
				if (mx==a[i][3])
				{
					int mi=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
					q[++tot]=mi;
				}
			}
			sort(q+1,q+1+tot);
			for (int i=1;i<=t[3]-n/2;i++)
			{
				sum-=q[i];
			}
		}
		printf("%d\n",sum);
	}
	return 0;
} 
