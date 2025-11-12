#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
}a[100005];
int n,t[100005],b[100005][5];
bool cmp1(node q,node p)
{
	return q.x>p.x;
}
bool cmp2(node q,node p)
{
	return q.y>p.y;
}
bool cmp3(node q,node p)
{
	return q.z>p.z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans1=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
//			for(int j=1;j<=3;j++)
//			{
				scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
//				if(b[i][1].x<a[i][j])
//				{
//					b[i][3]=b[i][2];
//					b[i][2]=b[i][1];
//					b[i][1].x=a[i][j];
//					b[i][1].y=j;
//				}
//				else if(b[i][2].x<a[i][j])
//				{
//					b[i][3]=b[i][2];
//					b[i][2].x=a[i][j];
//					b[i][2].y=j;
//				}
//				else
//				{
//					b[i][3].x=a[i][j];
//					b[i][3].y=j;
//				}
//			}
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++)
			b[i][1]=a[i].x;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++)
			b[i][2]=a[i].y;
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++)
			b[i][3]=a[i].z;
		for(int j=1;j<=n/2;j++)
		{
			for(int k=1;k<=n/2;k++)
			{
				memset(t,0,sizeof(t));
				int ans=0;
				int l=n-k-j;
				if(l>n/2)
					continue;
				for(int i=1;i<=n;i++)
					t[i]=1,ans+=b[i][1];
				for(int i=1;i<=n;i++)
					if(t[i]==0)
						t[i]=1,ans+=b[i][2];
				for(int i=1;i<=n;i++)
					if(t[i]==0)
						t[i]=1,ans+=b[i][3];
				ans1=max(ans1,ans);
			}
		}
		printf("%d\n",ans1);
	}
}
