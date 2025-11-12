#include<bits\stdc++.h>
using namespace std;
int a[100050][3],m,b[100050][3],s[3],total,x[100050];
int n;
void club()
{
	cin>>n;
	m=n/2;
	for(int i=0;i<n;i++)//n
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2])
		{
			if(a[i][3]>=a[i][1])
			{
				b[i][1]=3;b[i][2]=1;b[i][3]=2;
			}else if(a[i][3]>=a[i][2])
			{
				b[i][1]=1;b[i][2]=3;b[i][3]=2;
			}else
			{
				b[i][1]=1;b[i][2]=2;b[i][3]=3;
			}
		}else
		{
			if(a[i][3]>=a[i][2])
			{
				b[i][1]=3;b[i][2]=2;b[i][3]=1;
			}else if(a[i][3]>=a[i][1])
			{
				b[i][1]=2;b[i][2]=3;b[i][3]=1;
			}else
			{
				b[i][1]=2;b[i][2]=1;b[i][3]=3;
			}
		}
		s[b[i][1]]++;//???guiyi
		x[i]=b[i][1];
		total+=a[i][x[i]];
	}
	if(s[1]>m)//n(s[1]-m)<n^2
	{
		for(int i=0;i<s[1]-m;i++)
		{
			int mi;
			for(int j=0;j<n;j++)
			{
				if(x[j]==1)
				{
					mi=j;
					break;	
				}
			}
			for(int j=mi+1;j<n;j++)
			{
				if(a[j][1]-a[j][b[j][2]]<a[mi][1]-a[mi][b[mi][2]] && x[j]==1)
				{
					mi=j;
				}
			}
			x[mi]=b[mi][2];
			total=total-a[mi][1]+a[mi][x[mi]];
		}
		
	}
	if(s[2]>m)//n(s[2]-m)<n^2
	{
		for(int i=0;i<s[2]-m;i++)
		{
			int mi;
			for(int j=0;j<n;j++)
			{
				if(x[j]==2)
				{
					mi=j;
					break;	
				}
			}
			for(int j=mi+1;j<n;j++)
			{
				if(a[j][2]-a[j][b[j][2]]<a[mi][2]-a[mi][b[mi][2]]&& x[j]==2)
				{
					mi=j;
				}
			}
			x[mi]=b[mi][2];
			total=total-a[mi][2]+a[mi][x[mi]];
		}
		
	}
	if(s[3]>m)//n(s[3]-m)<n^2
	{
		for(int i=0;i<s[3]-m;i++)
		{
			int mi;
			for(int j=0;j<n;j++)
			{
				if(x[j]==3)
				{
					mi=j;
					break;	
				}
			}
			for(int j=mi+1;j<n;j++)
			{
				if(a[j][3]-a[j][b[j][2]]<a[mi][3]-a[mi][b[mi][2]]&& x[j]==3)
				{
					mi=j;
				}
			}
			x[mi]=b[mi][2];
			total=total-a[mi][3]+a[mi][x[mi]];
		}
		
	}
	
	cout<<total;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		club();
	}//tn^2
 } 
