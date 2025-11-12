#include<bits/stdc++.h>
using namespace std;

unsigned int t,n,a[100003][4],ans[100003],anum[100003][4],z1,z2,z3;

void club(int val)
{	
	z1=z2=z3=0; 
	ans[val]=0;
	scanf("%d",&n);
	for(int i =1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i =1;i<=n;i++)
	{
		if(a[i][1]>=a[i][2])
		{
			if(a[i][2]>=a[i][3])
			{
				anum[i][1]=a[i][1];
				anum[i][2]=a[i][2];
				anum[i][3]=a[i][3];
			}
			else if(a[i][3]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				anum[i][1]=a[i][1];
				anum[i][3]=a[i][2];
				anum[i][2]=a[i][3];
			}
			else
			{
				anum[i][1]=a[i][3];
				anum[i][2]=a[i][1];
				anum[i][3]=a[i][2];
			}
		}
		else if(a[i][2]>=a[i][1])
		{
			if(a[i][1]>=a[i][3])
			{
				anum[i][1]=a[i][2];
				anum[i][2]=a[i][1];
				anum[i][3]=a[i][3];
			}
			else if(a[i][3]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				anum[i][1]=a[i][2];
				anum[i][2]=a[i][3];
				anum[i][3]=a[i][1];
			}
			else
			{
				anum[i][1]=a[i][3];
				anum[i][2]=a[i][2];
				anum[i][3]=a[i][1];
			}
		}
		
	}
	
	
	int nnum =n/2;
	for(int i =1; i<=n;i++)
	{	
		if(anum[i][1]==a[i][1])
		{	
			if(z1<=nnum)
			{
				z1++;
				ans[val]=ans[val]+anum[i][1];
			}
			else if(a[i][2]==anum[i][2])
			{	
				if(z2<=nnum)
				{
					z2++;
					ans[val]=ans[val]+anum[i][2];
				}
				else
				{
					z3++;
					ans[val]=ans[val]+anum[i][3];
				}
			}
			else
			{
				if(z3<=nnum)
				{
					z3++;
					ans[val]=ans[val]+anum[i][2];
				}
				else
				{
					z2++;
					ans[val]=ans[val]+anum[i][3];
				}
			}
		}
		else if(anum[i][1]==a[i][2])
		{
			if(z2<=nnum)
			{
				z2++;
				ans[val]=ans[val]+anum[i][1];
			}
			else if(a[i][2]==anum[i][1])
			{	
				if(z1<=nnum)
				{
					z1++;
					ans[val]=ans[val]+anum[i][2];
				}
				else
				{
					z3++;
					ans[val]=ans[val]+anum[i][3];
				}
			}
			else
			{
				if(z3<=nnum)
				{
					z3++;
					ans[val]=ans[val]+anum[i][2];
				}
				else
				{
					z1++;
					ans[val]=ans[val]+anum[i][3];
				}
			}
		}
		else
		{
			if(z3<=nnum)
			{
				z3++;
				ans[val]=ans[val]+anum[i][1];
			}
			else if(a[i][2]==anum[i][2])
			{	
				if(z2<=nnum)
				{
					z2++;
					ans[val]=ans[val]+anum[i][2];
				}
				else
				{
					z1++;
					ans[val]=ans[val]+anum[i][1];
				}
			}
			else
			{
				if(z2<=nnum)
				{
					z2++;
					ans[val]=ans[val]+anum[i][2];
				}
				else
				{
					z1++;
					ans[val]=ans[val]+anum[i][3];
				}
			}
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int m =1; m<=t;m++)
	{
		club(m);
	}
	for(int m =1; m<=t;m++)
	{
		printf("%d\n",ans[m]);
	} 
	return 0;	
} 
