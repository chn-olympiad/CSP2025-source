#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int x,y,z,vis;
}a[N];
int T,n,ans,flag;
int cnt[4],b[N];
bool cmpp(node a1,node b1)
{
	if(flag==1)
		return a1.x>b1.x;
	else if(flag==2)
		return a1.y>b1.y;
	return a1.z>b1.z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=cnt[1]=cnt[2]=cnt[3]=flag=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			int maxx=max(a[i].x,max(a[i].y,a[i].z)),t=(maxx==a[i].x?1:(maxx==a[i].y?2:3));
			cnt[t]++;
			a[i].vis=t;
			ans+=maxx;
		}
		if(cnt[1]>n/2)
			flag=1;
		else if(cnt[2]>n/2)
			flag=2;
		else if(cnt[3]>n/2)
			flag=3;
		if(flag)
		{
			sort(a+1,a+n+1,cmpp);
			int num=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].vis==flag)
				{
					
					if(flag==1)
						b[++num]=max(a[i].y,a[i].z)-a[i].x;
					else if(flag==2)
						b[++num]=max(a[i].x,a[i].z)-a[i].y;
					else
						b[++num]=max(a[i].x,a[i].y)-a[i].z;
				}
			}
			sort(b+1,b+num+1);
			for(int i=num;i>n/2;i--)
				ans+=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
