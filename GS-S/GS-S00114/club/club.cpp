#include<bits/stdc++.h>
using namespace std;
struct name{
	int x;
	int y;
	int z;
}a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,a_1=0,a_2=0,a_3=0,sum=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=0;i<n;i++)
		{
			if(a[i].x>a[i].y&&a[i].x>a[i].z)
			{
				a_1++;
				sum+=a[i].x;
			}
			else if(a[i].y>a[i].x&&a[i].y>a[i].z)
			{
				a_2++;
				sum+=a[i].y;
			}
			else
			{
				a_3++;
				sum+=a[i].z;
			}
		}
		if(a_1>n/2)
		{
			bool b;
			for(int i=n;i>0;i--)
			{
				b=0;
				for(int j=0;j<i;j++)
				{
					if(max(a[j].x-a[j].y,a[j].x-a[j].z)>max(a[j+1].x-a[j+1].y,a[j+1].x-a[j+1].z))
					{
						swap(a[j],a[j+1]);
						b=1;
					}
				}
				if(b==0)
				{
					break;
				}
			}
			for(int i=1;i<=a_1-n/2;i++)
			{
				sum-=a[i].x;
				if(a[i].y>=a[i].z)
				{
					sum+=a[i].y;
				}
				else
				{
					sum+=a[i].z;
				}
			}
		}
		else if(a_2>n/2)
		{
			bool b;
			for(int i=n;i>0;i--)
			{
				b=0;
				for(int j=0;j<i;j++)
				{
					if(max(a[j].y-a[j].x,a[j].y-a[j].z)>max(a[j+1].y-a[j+1].x,a[j+1].y-a[j+1].z))
					{
						swap(a[j],a[j+1]);
						b=1;
					}
				}
				if(b==0)
				{
					break;
				}
			}
			for(int i=1;i<=a_2-n/2;i++)
			{
				sum-=a[i].y;
				if(a[i].x>=a[i].z)
				{
					sum+=a[i].x;
				}
				else
				{
					sum+=a[i].z;
				}
			}
		}
		else if(a_3>n/2)
		{
			bool b;
			for(int i=n;i>0;i--)
			{
				b=0;
				for(int j=0;j<i;j++)
				{
					if(max(a[j].z-a[j].y,a[j].z-a[j].x)>max(a[j+1].z-a[j+1].y,a[j+1].z-a[j+1].x))
					{
						swap(a[j],a[j+1]);
						b=1;
					}
				}
				if(b==0)
				{
					break;
				}
			}
			for(int i=1;i<=a_2-n/2;i++)
			{
				sum-=a[i].z;
				if(a[i].x>=a[i].y)
				{
					sum+=a[i].x;
				}
				else
				{
					sum+=a[i].y;
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
