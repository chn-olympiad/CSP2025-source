#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e5+1;
int t,n,yuan[MAXN][5],go[MAXN];
int sum=0,ren[5];
int max_n(int a,int b,int c,int l)
{
	if(a>b&&a>c)
	{
		ren[0]++;
		go[l]=0;
		return a;
	}
	if(b>a&&b>c)
	{
		ren[1]++;
		go[l]=1;
		return b;
	}
	if(c>a&&c>b)
	{
		ren[2]++;
		go[l]=2;
		return c;
	}
	if(a==b)
	{
		if(ren[0]>ren[1])
		{
			ren[1]++;
			go[l]=1;
		}
		ren[0]++;
		go[l]=0;
		return a;
	}
	if(a==c)
	{
		if(ren[0]>ren[2])
		{
			go[l]=2;
			ren[2]++;
		}
		ren[0]++;
		go[l]=0;
		return a;
	}
	if(b==c)
	{
		if(ren[2]>ren[1])
		{
			ren[1]++;
			go[l]=1;
		}
		ren[2]++;
		go[l]=2;
		return b;
	}
	ren[0]++;
	return a;
}
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0; i<t; i++)
	{
		sum=0;
		for(int j=0; j<5; j++)
		{
			ren[j]=0;
		}
		cin>>n;
		for(int j=0; j<n; j++)
		{
			cin>>yuan[j][0]>>yuan[j][1]>>yuan[j][2];
			yuan[j][3]=max_n(yuan[j][0],yuan[j][1],yuan[j][2],j);
			sum+=yuan[j][3];
		}
		bool flag=true;
		for(int j=0; j<3; j++)
		{
			if(ren[j]>(n/2))
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			cout<<sum<<endl;
		}
		else
		{

			while(true)
			{
				int flag;
				int maxn=0;
				if(ren[0]>(n/2))
				{
					for(int j=0; j<n; j++)
					{
						if(maxn<min(abs(yuan[j][0]-yuan[j][1]),abs(yuan[j][0]-yuan[j][2]))&&go[j]==0)
						{
							
							flag=j;
						}
					}
					if(abs(yuan[flag][0]-yuan[flag][1])>abs(yuan[flag][0]-yuan[flag][2]))
					{
						ren[2]++;
						sum-=abs(yuan[flag][0]-yuan[flag][2]);
					}
					else
					{
						ren[1]++;
						sum-=abs(yuan[flag][0]-yuan[flag][1]);
					}
					ren[0]--;
				}
				if(ren[1]>(n/2))
				{
					for(int j=0; j<n; j++)
					{
						if(maxn<min(abs(yuan[j][1]-yuan[j][2]),abs(yuan[j][1]-yuan[j][0]))&&go[j]==1)
						{
							flag=j;
						}
					}
					if(abs(yuan[flag][1]-yuan[flag][2])>abs(yuan[flag][1]-yuan[flag][0]))
					{
						ren[0]++;
						sum-=abs(yuan[flag][1]-yuan[flag][0]);
					}
					else
					{
						ren[2]++;
						sum-=abs(yuan[flag][1]-yuan[flag][2]);
					}
					ren[1]--;
				}
				if(ren[2]>(n/2))
				{
					for(int j=0; j<n; j++)
					{
						if(maxn<min(abs(yuan[j][2]-yuan[j][1]),abs(yuan[j][0]-yuan[j][2]))&&go[j]==2)
						{
							flag=j;
						}
					}
					if(abs(yuan[flag][2]-yuan[flag][1])>abs(yuan[flag][0]-yuan[flag][2]))
					{
						ren[0]++;
						sum-=abs(yuan[flag][0]-yuan[flag][2]);
					}
					else
					{
						ren[1]++;
						sum-=abs(yuan[flag][2]-yuan[flag][1]);
					}
					ren[2]--;
				}
				if(ren[1]<=(n/2)&&ren[2]<=(n/2)&&ren[0]<=(n/2))  break;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
