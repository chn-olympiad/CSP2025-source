#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[100005];
int b[100005];
int c[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	scanf("%d",&T);
	while(T--)
	{
		int go_1[100005];
		int go_2[100005];
		int go_3[100005];
		int ans=0;
		int go1=0,go2=0,go3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i]){go_1[++go1]=min(a[i]-b[i],a[i]-c[i]);ans+=a[i];continue;}
			if(b[i]>=a[i]&&b[i]>=c[i]){go_2[++go2]=min(b[i]-c[i],b[i]-a[i]);ans+=b[i];continue;}
			if(c[i]>=b[i]&&c[i]>=a[i]){go_3[++go3]=min(c[i]-a[i],c[i]-b[i]);ans+=c[i];continue;}
		}	
		if(go1>(n/2))
		{
			sort(go_1+1,go_1+go1+1);
			for(int i=1;i<=(go1-(n/2));i++)
			{
				ans-=go_1[i]; 
			}
			printf("%d\n",ans);
			continue;
		}
		if(go2>(n/2))
		{
			sort(go_2+1,go_2+go2+1);
			for(int i=1;i<=(go2-(n/2));i++)
			{
				ans-=go_2[i]; 
			}
			printf("%d\n",ans);
			continue;
		}
		if(go3>(n/2))
		{
			sort(go_3+1,go_3+go3+1);
			for(int i=1;i<=(go3-(n/2));i++)
			{
				ans-=go_3[i]; 
			}
			printf("%d\n",ans);
			continue;
		}
		printf("%d\n",ans);
	}	
	return 0;
} 
