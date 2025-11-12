//GZ-S00282 贵阳市第一中学 柳保屹 
#include<bits/stdc++.h>
using namespace std;

int cnt[4],ans;
struct ren{
	int a1;
	int a2;
	int a3;
	int za;
	int ba;
	int jh;
}a[100010];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			a[j].za=max(a[j].a1,max(a[j].a2,a[j].a3));
			if(a[j].za==a[j].a1) a[j].ba=1;
			else if(a[j].za==a[j].a2) a[j].ba=2;
			else a[j].ba=3;
			cnt[a[j].ba]++;
			ans+=a[j].za;
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2) cout<<ans<<endl;
		else
		{
			if(cnt[1]>n/2)
			{
				int cha=cnt[1]-n/2;
				for(int k=1;k<=cha;k++)
				{
					int minx=201000,minw;
					for(int j=1;j<=n;j++)
					{
						if(a[j].ba==1)
						{
							if(a[j].a2>a[j].a3) a[j].jh=a[j].a1-a[j].a2;
							else a[j].jh=a[j].a1-a[j].a3;
							if(a[j].jh<minx)
							{
								minx=a[j].jh;
								minw=j;
							}
						}
					}
					ans-=a[minw].jh;
					if(a[minw].a2>a[minw].a3) a[minw].ba=2;
					else a[minw].ba=3;
					cnt[a[minw].ba]++;
				}
				if(cnt[2]>n/2)
				{
					cha=cnt[2]-n/2;
					for(int k=1;k<=cha;k++)
					{
						int minx=201000,minw;
						for(int j=1;j<=n;j++)
						{
							if(a[j].ba==2)
							{
								a[j].jh=a[j].a2-a[j].a3;
								if(a[j].jh<minx)
								{
									minx=a[j].jh;
									minw=j;
								}
							}
						}
						ans-=a[minw].jh;
						a[minw].ba=3;
					}
				}
			}
			if(cnt[2]>n/2)
			{
				int cha=cnt[2]-n/2;
				for(int k=1;k<=cha;k++)
				{
					int minx=201000,minw;
					for(int j=1;j<=n;j++)
					{
						if(a[j].ba==2)
						{
							if(a[j].a1>a[j].a3) a[j].jh=a[j].a2-a[j].a1;
							else a[j].jh=a[j].a2-a[j].a3;
							if(a[j].jh<minx)
							{
								minx=a[j].jh;
								minw=j;
							}
						}
					}
					ans-=a[minw].jh;
					if(a[minw].a1>a[minw].a3) a[minw].ba=1;
					else a[minw].ba=3;
					cnt[a[minw].ba]++;
				}
				if(cnt[3]>n/2)
				{
					cha=cnt[3]-n/2;
					for(int k=1;k<=cha;k++)
					{
						int minx=201000,minw;
						for(int j=1;j<=n;j++)
						{
							if(a[j].ba==3)
							{
								a[j].jh=a[j].a3-a[j].a1;
								if(a[j].jh<minx)
								{
									minx=a[j].jh;
									minw=j;
								}
							}
						}
						ans-=a[minw].jh;
						a[minw].ba=1;
					}
				}
			}
			if(cnt[3]>n/2)
			{
				int cha=cnt[3]-n/2;
				for(int k=1;k<=cha;k++)
				{
					int minx=201000,minw;
					for(int j=1;j<=n;j++)
					{
						if(a[j].ba==3)
						{
							if(a[j].a1>a[j].a2) a[j].jh=a[j].a3-a[j].a1;
							else a[j].jh=a[j].a3-a[j].a2;
							if(a[j].jh<minx)
							{
								minx=a[j].jh;
								minw=j;
							}
						}
					}
					ans-=a[minw].jh;
					if(a[minw].a1>a[minw].a2) a[minw].ba=1;
					else a[minw].ba=2;
					cnt[a[minw].ba]++;
				}
				if(cnt[1]>n/2)
				{
					cha=cnt[1]-n/2;
					for(int k=1;k<=cha;k++)
					{
						int minx=201000,minw;
						for(int j=1;j<=n;j++)
						{
							if(a[j].ba==1)
							{
								a[j].jh=a[j].a1-a[j].a2;
								if(a[j].jh<minx)
								{
									minx=a[j].jh;
									minw=j;
								}
							}
						}
						ans-=a[minw].jh;
						a[minw].ba=2;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

