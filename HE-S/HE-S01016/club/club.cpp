#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a1[100005];
int a2[100005];
int a3[100005];
int s,u;
int h;
int sum;
int b1,b2,b3;
int s1,s2;
int y;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		s=0;
		sum=0;
		u=0;
		b1=0;
		b2=0;
		b3=0;
		s1=0;
		s2=0;
		y=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]==0&&a3[i]==0)
			{
				s++;
			}
			if(a1[i]==0&&a3[i]==0)
			{
				s1++;
			}
			if(a1[i]==0&&a2[i]==0)
			{
				s2++;
			}
			if(a3[i]==0)
			{
				u++;
			}
		}
		if(s==n)
		{
			for(int k=1;k<=n-1;k++)
			{
			for(int i=1;i<=n;i++)
			{
				if(i==1)
				{
					continue;
				}
				if(a1[i]>a1[i-1])
				{
					h=a1[i];
					a1[i]=a1[i-1];
					a1[i-1]=h;
				}
			}
			}
			for(int i=1;i<=n/2;i++)
			{
				sum=sum+a1[i];
			}
			cout<<sum;
			continue;
		}else if(s1==n)
		{
			for(int k=1;k<=n-1;k++)
			{
			for(int i=1;i<=n;i++)
			{
				if(i==1)
				{
					continue;
				}
				if(a2[i]>=a2[i-1])
				{
					h=a2[i];
					a2[i]=a2[i-1];
					a2[i-1]=h;
				}
			}
		}
			for(int i=1;i<=n/2;i++)
			{
				sum=sum+a2[i];
			}
			cout<<sum;
			continue;
		}else if(s2==n)
		{
			for(int k=1;k<=n-1;k++)
			{
			for(int i=1;i<=n;i++)
			{
				if(i==1)
				{
					continue;
				}
				if(a3[i]>=a3[i-1])
				{
					h=a3[i];
					a3[i]=a3[i-1];
					a3[i-1]=h;
				}
			}
		}
			for(int i=1;i<=n/2;i++)
			{
				sum=sum+a3[i];
			}
			cout<<sum;
			continue;
		}/*else if(u==n)
		{
			for(int i=1;i<=n;i++)
			{
				if(a1[i]>a2[i])
				{
					sum=sum+a1[i];
					b1++;
				}else if(a1[i]<a2[i])
				{
					sum=sum+a2[i];
					b2++;
				}else
				{
					sum=sum+a1[i];
					if(y%2==0)
					{
						b1++;
					}else
					{
						b2++;
					}
					
				}
			}
		}*/
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a1[i]>=a2[i]&&a1[i]>=a3[i])
				{
					sum=sum+a1[i];
					b1++;
				}else if(a2[i]>=a1[i]&&a2[i]>=a3[i])
				{
					sum=sum+a2[i];
					b2++;
				}else if(a3[i]>=a2[i]&&a3[i]>a1[i])
				{
					sum=sum+a3[i];
					b3++;
				}
			}
			if((b1<=(n/2))&&(b2<=(n/2))&&(b3<=(n/2)))
			{
				cout<<sum;
			}
			else
			{
				cout<<sum;
			 } 
		}
	}
	return 0;
 } 
