#include <bits/stdc++.h>
using namespace std;
int t,c[6],n,a[100001][4],l=0;
bool p(int h,int k)
{
	for(int i=1;i<=n;i++)
		if(a[h][k]<a[i][k])
			return false;
	return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int q=t;
	while(q)
	{
		int z=0;
		int b1=0,b2=0,b3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++)
		{
			if (a[i][1]>a[i][2]&&a[i][1]>a[i][3])
			{
				if(b1<n/2&&p(i,1))
				{
					z+=a[i][1];
					b1++;
				}
				else
				{
					if(a[i][2]>a[i][3]&&b2<n/2&&p(i,2))
					{
						z+=a[i][2];
						b2++;
					}
					else if(b3<n/2&&p(i,3))
					{
						z+=a[i][3];
						b3++;
					}	
				}
			}
			else if (a[i][2]>a[i][1]&&a[i][2]>a[i][3])
			{
				if(b2<n/2&&p(i,2))
				{
					z+=a[i][2];
					b2++;
				}
				else
				{
					if(a[i][1]>a[i][3]&&b1<n/2&&p(i,1))
					{
						z+=a[i][1];
						b1++;
					}
					else if(b3<n/2&&p(i,3))
					{
						z+=a[i][3];
						b3++;
					}	
				}
			}
			else if (a[i][3]>a[i][1]&&a[i][3]>a[i][2])
			{
				if(b3<n/2&&p(i,3))
				{
					z+=a[i][3];
					b3++;
				}
				else
				{
					if(a[i][1]>a[i][2]&&b1<n/2&&p(i,1))
					{
						z+=a[i][1];
						b1++;
					}
					else if(b2<n/2&&p(i,2))
					{
						z+=a[i][2];
						b2++;
					}	
				}
			}
		}
		l++;
		c[l]=z;
		q--;
	}
	for(int i=1;i<=t;i++)
		cout<<c[i]<<endl;
	return 0;
} 
