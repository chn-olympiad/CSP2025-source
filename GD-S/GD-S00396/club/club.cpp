#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","f",stdout);
	int t;
	cin>>t;
	for(int t1=1;t1<=t;t1++)
	{
		int n;
		int e=0,f=0,g1=0,g2=0,g3=0;
		int amax=0,max=0;
		cin>>n;
		int a[100005][5];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int t2=1;t2<=3*n;t2++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(a[i][j]>=a[i+1][j]&&a[i][j]>=a[i][j+1]&&a[i][j]>=a[i+1][j+1]&&a[i][j]>=a[i+1][j-1]&&a[i][j]>=a[i-1][j]&&a[i][j]>=a[i][j-1]&&a[i][j]>=a[i-1][j-1]&&a[i][j]>=a[i-1][j+1])
					{
						if(a[i][j]>=amax)
						{
							amax=a[i][j];
							e=i;
							f=j;	
						}
					}
				}
			}
			if(f==1&&g1<=n/2)
			{
				g1=g1+1;
				max=max+amax;
				for(int i=1;i<=3;i++)
				{
				a[e][i]=0;
				}
			}
			else if(f==2&&g2<n/2)
			{
				g2=g2+1;
				max=max+amax;
				for(int i=1;i<=3;i++)
				{
				a[e][i]=0;
				}
			}
			else if(f==3&&g3<n/2)
			{
				g3=g3+1;
				max=max+amax;
				for(int i=1;i<=3;i++)
				{
				a[e][i]=0;
				}
		    }
			if(g1+g2+g3==n)
			{
				break;
			}
			a[e][f]=0;
			amax=0;
		}
		cout<<max;
	}
	return 0;
}
