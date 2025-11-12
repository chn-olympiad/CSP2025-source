#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,s=0,s1=0,s2=0,sum=0,t;
	cin>>t;
	for(int c=0;c<t;c++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		int l=0,k=0,d1=0,d2=0;
		for(int i=0;i<n;i++)
		{
			l=a[i][0];
			for(int j=0;j<3;j++)
			{
				k=a[i][j];
				if(l<k)
				{
					d1=l;
					l=k;
					k=d1;
					d1=j;
				}		
		}
		if(d1==0&&s<=n/2)
		{
			s++;
			sum+=l;
		}
		if(d1==0&&s>n/2)
		{
			for(int w=0;w<n;w++)
			{
				int ll=a[w][1],kk=0;
				for(int q=1;q<3;q++)
				{
					kk=a[w][q];
					if(ll<kk)
					{
						d2=q;
						int t=ll;
						ll=kk;
						kk=t;
					}
				}
				if(d2==2&&s1<n/2)
				{
					s1++;
					sum+=ll;
				}
				else
				{
					s2++;
					sum+=kk;
				}
			}
		}	
		if(d1==1&&s1<=n/2)
		{
			s1++;
			sum+=l;
		}
		if(d1==1&&s1>n/2)
		{
			for(int z=0;z<n;z++)
			{
				int ll=a[z][0],kk=0;
				for(int y=1;y<3;y++)
				{
					if(y==2)
					{
						y++;
					}
					kk=a[z][y];
					if(ll<kk)
					{
						d2=y;
						int t=ll;
						ll=kk;
						kk=t;
					}
				}
				if(d2==1&&s1<n/2)
				{
					s++;
					sum+=ll;
				}
				else
				{
					s++;
					sum+=kk;
				}
			}
		}
		if(d1==2&&s2<=n/2)
		{
			s2++;
			sum+=l;
		}
		if(d1==2&&s2>n/2)
		{
			for(int z=0;z<n;z++)
			{
				int ll=a[z][0],kk=0;
				for(int y=0;y<2;y++)
				{
					kk=a[z][y];
					if(ll<kk)
					{
						d2=y;
						int t=ll;
						ll=kk;
						kk=t;
					}
				}
				if(d2==1&&s<n/2)
				{
					s1++;
					sum+=ll;
				}
				else
				{
					s1++;
					sum+=kk;
				}
			}
		}
	}
	cout<<sum<<endl;
	sum=0;
	l=0,s=0,s1=0,s2=0,k=0,d1=0,d2=0;
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				a[i][j]=0;
			}
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
