#include <bits/stdc++.h>
using namespace std;
int a[5],sum,pia[50005],pia1[50005],pia2[50005];
struct Xingchenyuan
{
	int x,y,z;
}b[100005];
bool diyige(int x)
{
	sort(pia+1,pia+a[1]+1);
	if (x>=pia[1])
	{
		sum-=pia[1];
		sum+=x;
		return true;
	}
	else
	{
		return false;
	}
}
bool dierge(int x)
{
	sort(pia1+1,pia1+a[2]+1);
	if (x>=pia1[1])
	{
		sum-=pia1[1];
		sum+=x;
		return true;
	}
	else
	{
		return false;
	}
}
bool disange(int x)
{
	sort(pia2+1,pia2+a[3]+1);
	if (x>=pia2[1])
	{
		sum-=pia2[1];
		sum+=x;
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		sum=0;
		for (int i=1;i<=n;i++)
		{
			cin>>b[i].x>>b[i].y>>b[i].z;
			if (b[i].x>=b[i].y && b[i].x>=b[i].z && a[1]<=(n/2))
			{
				a[1]++;
				pia[i]=b[i].x;
				sum+=b[i].x;
			}
			else if (b[i].x>=b[i].y && b[i].x>=b[i].z && a[1]>(n/2))
			{
				if (diyige(b[i].x))
				{
					a[1]++;
					pia[i]=b[i].x;
				}
			}
			if (b[i].y>=b[i].x && b[i].y>=b[i].z && a[2]<=(n/2))
			{
				a[2]++;
				pia1[i]=b[i].y;
				sum+=b[i].y;
			}
			else if (b[i].y>=b[i].x && b[i].y>=b[i].z && a[2]>(n/2))
			{
				if (dierge(b[i].y))
				{
					a[2]++;
					pia1[i]=b[i].y;
				}
			}
			if (b[i].z>=b[i].y && b[i].z>=b[i].x && a[3]<=(n/2))
			{
				a[3]++;
				pia2[i]=b[i].z;
				sum+=b[i].z;
			}
			else if (b[i].z>=b[i].y && b[i].z>=b[i].x && a[3]>(n/2))
			{
				if (disange(b[i].z))
				{
					a[3]++;
					pia2[i]=b[i].z;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
