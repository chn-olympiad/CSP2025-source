#include<bits/stdc++.h>
using namespace std;
int n,a[100005][5],p[5],ans=0,a1[50505],a2[50505],a3[50505];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int v=1;v<=t;v++)
	{
		memset(a1,-1,sizeof(a1));
		memset(a2,-1,sizeof(a2));
		memset(a3,-1,sizeof(a3));
		p[1]=0;p[2]=0;p[3]=0;
		ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++){cin>>a[i][j];}
		ans=ans+max(a[i][3],max(a[i][2],a[i][1]));
		if(a[i][2]>a[i][1])
		{
			if(a[i][3]>a[i][2])
			{
				p[3]++;
				a3[i]=a[i][3];
			}
			else
			{
				p[2]++;
				a2[i]=a[i][2];
			}
		}
		else
		{
			if(a[i][3]>a[i][1])
			{
				p[3]++;
				a3[i]=a[i][3];
			}
			else
			{
				p[1]++;
				a1[i]=a[i][1];
			}
		}
	}
	/**/
	int minn=1e5,w=0;
	while(p[1]>n/2)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]<=minn&&a1[i]!=-1)
			{
				w=i;
				minn=min(minn,a[i][1]);
			}
		}
		ans=ans-a[w][1];
		ans=ans+max(a[w][2],a[w][3]);
		if(a[w][2]>a[w][3])
		{
			p[1]--;
			p[2]++;
		}
		else
		{
			p[1]--;
			p[3]++;
		}
	}
	w=0,minn=1e5;
	while(p[2]>n/2)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i][2]<=minn&&a2[i]!=-1)
			{
				w=i;
				minn=min(minn,a[i][2]);
			}
		}
		ans=ans-a[w][2];
		ans=ans+max(a[w][1],a[w][3]);
		if(a[w][1]>a[w][3])
		{
			p[2]--;
			p[1]++;
		}
		else
		{
			p[2]--;
			p[3]++;
		}
	}
	w=0,minn=1e5;
	while(p[3]>n/2)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i][3]<=minn&&a3[i]!=-1)
			{
				w=i;
				minn=min(minn,a[i][3]);
			}
		}
		ans=ans-a[w][3];
		ans=ans+max(a[w][1],a[w][2]);
		if(a[w][2]>a[w][1])
		{
			p[3]--;
			p[2]++;
		}
		else
		{
			p[3]--;
			p[1]++;
		}
	}
	cout<<ans<<endl;}
	return 0;
}
