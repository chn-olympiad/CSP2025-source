#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		long long n=0,a[100000][10],b[3]={0,0,0},max=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=2;j++)
			{
				cin>>a[i][j];
			}
			a[i][9]=0;
		}
		for(int i=0;i<n;i++)
		{
			int max,maxb=0;
			max=a[i][0];
			for(int j=1;j<=2;j++)
			{
				if(max<a[i][j])
				{
					max=a[i][j];
					maxb=j;
				}
			}
			a[i][3]=maxb;
			if(maxb==0)
			{
				if(a[i][1]>a[i][2])
				{
					a[i][4]=1;
					a[i][6]=2;
				}
				else
				{
					a[i][4]=2;
					a[i][6]=1;
				}
			}
			if(maxb==1)
			{
				if(a[i][0]>a[i][2])
				{
					a[i][4]=0;
					a[i][6]=2;
				}
				else
				{
					a[i][4]=2;
					a[i][6]=0;
				}
			}
			if(maxb==2)
			{
				if(a[i][1]>a[i][0])
				{
					a[i][4]=1;
					a[i][6]=0;
				}
				else
				{
					a[i][4]=0;
					a[i][6]=1;
				}
			}
				a[i][5]=a[i][a[i][3]]-a[i][a[i][4]];
				a[i][7]=a[i][a[i][4]]-a[i][a[i][6]];
		}
		for(int i=0;i<n;i++)
		{
			int maxx=-1,maxy=-1,maxz=-1;
			for(int j=0;j<n;j++)
			{
				if(a[j][9]==0)
				{
					if((a[j][5]>maxx)||(a[j][5]=maxx&&a[j][7]>=maxy))
					{
							maxx=a[j][5];
							maxy=a[j][7];
							maxz=j;
					}
				}
			
			}
				if(b[a[maxz][3]]<n/2)
				{
					b[a[maxz][3]]++;
					a[maxz][8]=a[maxz][3];
					a[maxz][9]=1;
				}
				else if(b[a[maxz][4]]<n/2)
				{
					b[a[maxz][4]]++;
					a[maxz][8]=a[maxz][4];
					a[maxz][9]=1;
				}
				else
				{
					b[a[maxz][6]]++;
					a[maxz][8]=a[maxz][6];
					a[maxz][9]=1;
				}
			
		}
		for(int i=0;i<n;i++)
		{
			max+=a[i][a[i][8]];
		}
		cout<<max<<endl;
	}
	return 0;
}
