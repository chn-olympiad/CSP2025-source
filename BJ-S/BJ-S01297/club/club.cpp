#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c;
	int maxx,minx,midx;
} s[1000005];
int c[4][1000005];
bool cmp(int x,int y)
{
	int maxx=s[x].maxx;
	int midx=s[x].midx;
	int maxy=s[y].maxx;
	int midy=s[y].midx;
	return maxx-midx<maxy-midy;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		memset(c,0,sizeof(c));
		int n;
		cin>>n;
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			int maxx=max(s[i].a,max(s[i].b,s[i].c));
			int minx=min(s[i].a,min(s[i].b,s[i].c));
			int midx=s[i].a+s[i].b+s[i].c-maxx-minx;
			if (maxx==s[i].a) c[1][++c[1][0]]=i;
			else if (maxx==s[i].b) c[2][++c[2][0]]=i;
			else if (maxx==s[i].c) c[3][++c[3][0]]=i;
			sum+=maxx;
			s[i].maxx=maxx;
			s[i].minx=minx;
			s[i].midx=midx;
		}
		if (c[1][0]<=n/2&&c[2][0]<=n/2&&c[3][0]<=n/2)
		{
			cout<<sum<<endl;
			continue;
		}
		if (c[1][0]>n/2)
		{
			sort(c[1]+1,c[1]+c[1][0]+1,cmp);
			for (int i=1;i<=c[1][0]-n/2;i++)
			{
				int x=c[1][i];
				sum-=s[x].maxx-s[x].midx;
			}
			cout<<sum;
		}
		else if (c[2][0]>n/2)
		{
			sort(c[2]+1,c[2]+c[2][0]+1,cmp);
			for (int i=1;i<=c[2][0]-n/2;i++)
			{
				int x=c[2][i];
				sum-=s[x].maxx-s[x].midx;
			}
			cout<<sum;
		}
		if (c[3][0]>n/2)
		{
			sort(c[3]+1,c[3]+c[3][0]+1,cmp);
			for (int i=1;i<=c[3][0]-n/2;i++)
			{
				int x=c[3][i];
				sum-=s[x].maxx-s[x].midx;
			}
			cout<<sum;
		}
		cout<<endl;
	}
	return 0;
}
