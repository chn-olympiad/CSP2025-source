#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int a[100005][4];
int ans1=0,c1,c2,c3;
int b1[100050],b2[100050],b3[100050],b4[100050];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		c1=c2=c3=0;
		ans1=0; 
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) scanf("%d",&a[i][j]);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) b1[++c1]=i;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) b2[++c2]=i;
			else b3[++c3]=i;
			ans1+=max(max(a[i][1],a[i][2]),a[i][3]); 
		}
		if(c1>n/2)
		{
			for(int i=1;i<=c1;i++)
			{
				b4[i]=min(a[b1[i]][1]-a[b1[i]][2],a[b1[i]][1]-a[b1[i]][3]);
			}
			sort(b4+1,b4+1+c1); 
			for(int i=1;i<=c1-n/2;i++) ans1-=b4[i];
		}
		else if(c2>n/2)
		{
			for(int i=1;i<=c2;i++)
			{
				b4[i]=min(a[b2[i]][2]-a[b2[i]][1],a[b2[i]][2]-a[b2[i]][3]);
			}
			sort(b4+1,b4+1+c2); 
			for(int i=1;i<=c2-n/2;i++) ans1-=b4[i];
		}
		else if(c3>n/2)
		{
			for(int i=1;i<=c3;i++)
			{
				b4[i]=min(a[b3[i]][3]-a[b3[i]][2],a[b3[i]][3]-a[b3[i]][1]);
			}
			sort(b4+1,b4+1+c3); 
			for(int i=1;i<=c3-n/2;i++) ans1-=b4[i];
		}
		printf("%d\n",ans1);
	}
	
	
	return 0;
}
