#include<bits/stdc++.h>
using namespace std;
long long t,n[5],a[6][1000001][4],ans[6],b[4],d[1000001],e[1000001],x=0;
int da(long long a,long long b,long long  c)
{
	
	if(a==max(a,b)&&a==max(a,c))
	{
		return 1;
	}
	if(b==max(a,b)&&b==max(b,c))
	{
		return 2;
	}
	if(c==max(c,b)&&c==max(a,c))
	{
		return 3;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n[i];
		for(int j=0;j<n[i];j++)
		{
			for(int k=0;k<3;k++)
			{
				cin>>a[i][j][k]; 
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		b[0]=0;
		b[1]=0;
		b[2]=0;
		for(int j=0;j<n[i];j++)
		{
			if(da(a[i][j][0],a[i][j][1],a[i][j][2])==1)
			{
				ans[i]+=a[i][j][0];
				
				b[0]++; 
				d[j]=1;
			
			}
			if(da(a[i][j][0],a[i][j][1],a[i][j][2])==2)
			{
				ans[i]+=a[i][j][1];
				
				b[1]++;
				d[j]=2;
			}
			if(da(a[i][j][0],a[i][j][1],a[i][j][2])==3)
			{
				ans[i]+=a[i][j][2];
				
				b[2]++;
				d[j]=3;
			}
		}
		if(b[0]>n[i]/2||b[1]>n[i]/2||b[2]>n[i]/2)
		{
			if(b[0]>n[i]/2)
			{
				for(int h=0;h<b[0];h++)
				{
					if(d[h]==1)
					{
						e[x]=a[i][h][0]-max(a[i][h][1],a[i][h][2]);
						x++;
					}
				}
				sort(e,e+x);	
				for(;b[0]>n[i]/2;b[0]--)
				{
					ans[i]-=e[b[0]];
				}
			}
			if(b[1]>n[i]/2)
			{
				for(int h=0;h<b[1];h++)
				{
					if(d[h]==2)
					{
						e[x]=a[i][h][1]-max(a[i][h][0],a[i][h][2]);
						x++;
					}
				}
				sort(e,e+x);
				for(;b[1]>n[i]/2;b[1]--)
				{
					ans[i]-=e[b[1]];
				}
			}
			if(b[2]>n[i]/2)
			{
				for(int h=0;h<b[2];h++)
				{
					if(d[h]==3)
					{
						e[x]=a[i][h][2]-max(a[i][h][0],a[i][h][1]);
						x++;
					}
				}
				sort(e,e+x);	
				for(;b[2]>n[i]/2;b[2]--)
				{
					ans[i]-=e[b[2]];
				}
			}
			cout<<ans[i]<<" ";
		}
		else	cout<<ans[i]<<" ";
	}
}
