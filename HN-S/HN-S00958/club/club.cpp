#include<bits/stdc++.h>
using namespace std;
long long int t,n,ans=0,s1=0,s2=0,s3=0;
struct node
{
	long long int a1[4],maxx1,maxx2,maxx3,d,d1;
}a[100010];
bool cmp(node x,node y)
{
	return (x.a1[x.maxx1]>y.a1[y.maxx1])||(x.a1[x.maxx1]==y.a1[y.maxx1]&&x.a1[x.maxx2]>y.a1[y.maxx2])||(x.a1[x.maxx1]==y.a1[y.maxx1]&&x.a1[x.maxx2]==y.a1[y.maxx2]&&x.a1[x.maxx3]>y.a1[y.maxx3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		s1=0;
		s2=0;
		s3=0;
		cin>>n;
		for(long long int i=1;i<=n;i++)
		{
			a[i].d=0;
			a[i].d1=0;
			a[i].maxx1=0;
			a[i].maxx2=0;
			a[i].maxx3=0;
			cin>>a[i].a1[1]>>a[i].a1[2]>>a[i].a1[3];
			a[i].maxx1=max(a[i].maxx1,max(a[i].a1[1],max(a[i].a1[2],a[i].a1[3])));
			a[i].maxx3=min(a[i].maxx1,min(a[i].a1[1],min(a[i].a1[2],a[i].a1[3])));
			if(a[i].maxx1==a[i].a1[1])
			{
				a[i].maxx1=1;
			}
			else if(a[i].maxx1==a[i].a1[2])
			{
				a[i].maxx1=2;
			}
			else
			{
				a[i].maxx1=3;
			}
			if(a[i].maxx3==a[i].a1[1])
			{
				a[i].maxx3=1;
			}
			else if(a[i].maxx3==a[i].a1[2])
			{
				a[i].maxx3=2;
			}
			else
			{
				a[i].maxx3=3;
			}
			a[i].maxx2=6-a[i].maxx1-a[i].maxx3;
		}
		sort(a+1,a+n+1,cmp);
		/*for(int i=1;i<=n;i++)
		{
			cout<<a[i].a1[1]<<" "<<a[i].a1[2]<<" "<<a[i].a1[3]<<" "<<a[i].maxx1<<" "<<a[i].maxx2<<" "<<a[i].maxx3<<endl;
		}*/
		for(long long int i=1;i<=n;i++)
		{
			if(a[i].maxx1==1)
			{
				if(s1<n/2)
				{
					s1++;
					ans+=a[i].a1[1];
					a[i].d=a[i].a1[1];
				}
				else if(a[i].maxx2==2&&s2<n/2)
				{
					long long int s=0,flag=0,ss;
					for(int j=i-1;j>=1;j--)
					{
						if(a[j].d1==1)
						{
							if(ans-a[j].d+a[j].a1[2]+a[i].a1[1]>ans+a[i].a1[2]) 
							{
								flag=1;
								if(s<ans-a[j].d+a[j].a1[2]+a[i].a1[1])
								{
									s=ans-a[j].d+a[j].a1[2]+a[i].a1[1];
									ss=j;
									a[i].d1=1;
									a[i].d=a[i].a1[1];
								}
							}
						}
					}
					if(flag==1)
					{
						ans=s;
						a[ss].d1=2; 
						a[ss].d=a[s1].a1[2];
						s2++;
					}
					if(flag==0)
					{
						s2++;
						ans+=a[i].a1[2];
						a[i].d=a[i].a1[2];
						a[i].d1=2;
					}
				}
				else if(a[i].maxx2==3&&s3<n/2)
				{
					long long int s=0,flag=0,ss;
					for(int j=i-1;j>=1;j--)
					{
						if(a[j].d1==1)
						{
							if(ans-a[j].d+a[j].a1[3]+a[i].a1[1]>ans+a[i].a1[3]) 
							{
								flag=1;
								if(s<ans-a[j].d+a[j].a1[3]+a[i].a1[1])
								{
									s=ans-a[j].d+a[j].a1[3]+a[i].a1[1];
									ss=j;
									a[i].d1=1;
									a[i].d=a[i].a1[1];
								}
							}
						}
					}
					if(flag==1)
					{
						ans=s;
						a[ss].d1=3; 
						a[ss].d=a[s1].a1[3];
						s3++;
					}
					if(flag==0)
					{
						s3++;
						ans+=a[i].a1[3];
						a[i].d=a[i].a1[3];
						a[i].d1=3;
					}
				}
			}
			if(a[i].maxx1==2)
			{
				if(s2<n/2)
				{
					s2++;
					ans+=a[i].a1[2];
					a[i].d=a[i].a1[2];
					a[i].d1=2;
				}
				else if(a[i].maxx2==1&&s1<n/2)
				{
					long long int s=0,flag=0,ss;
					for(int j=i-1;j>=1;j--)
					{
						if(a[j].d1==2)
						{
							if(ans-a[j].d+a[j].a1[1]+a[i].a1[2]>ans+a[i].a1[1]) 
							{
								flag=1;
								if(s<ans-a[j].d+a[j].a1[1]+a[i].a1[2])
								{
									s=ans-a[j].d+a[j].a1[1]+a[i].a1[2];
									ss=j;
									a[i].d1=2;
									a[i].d=a[i].a1[2];
								}
							}
						}
					}
					if(flag==1)
					{
						ans=s;
						a[ss].d1=1; 
						a[ss].d=a[s1].a1[1];
						s1++;
					}
					if(flag==0)
					{
						s1++;
						ans+=a[i].a1[1];
						a[i].d=a[i].a1[1];
						a[i].d1=1;
					}
				}
				else if(a[i].maxx2==3&&s3<n/2)
				{
					long long int s=0,flag=0,ss;
					for(int j=i-1;j>=1;j--)
					{
						if(a[j].d1==2)
						{
							if(ans-a[j].d+a[j].a1[3]+a[i].a1[2]>ans+a[i].a1[3]) 
							{
								flag=1;
								if(s<ans-a[j].d+a[j].a1[3]+a[i].a1[2])
								{
									s=ans-a[j].d+a[j].a1[3]+a[i].a1[2];
									ss=j;
									a[i].d1=2;
									a[i].d=a[i].a1[2];
								}
							}
						}
					}
					if(flag==1)
					{
						ans=s;
						a[ss].d1=3; 
						a[ss].d=a[s1].a1[3];
						s3++;
					}
					if(flag==0)
					{
						s3++;
						ans+=a[i].a1[3];
						a[i].d=a[i].a1[3];
						a[i].d1=3;
					}
				}
			}
			if(a[i].maxx1==3)
			{
				if(s3<n/2)
				{
					s3++;
					ans+=a[i].a1[3];
					a[i].d=a[i].a1[3];
					a[i].d1=3;
				}
				else if(a[i].maxx2==2&&s2<n/2)
				{
					long long int s=0,flag=0,ss;
					for(int j=i-1;j>=1;j--)
					{
						if(a[j].d1==3)
						{
							if(ans-a[j].d+a[j].a1[2]+a[i].a1[3]>ans+a[i].a1[2]) 
							{
								flag=1;
								if(s<ans-a[j].d+a[j].a1[2]+a[i].a1[3])
								{
									s=ans-a[j].d+a[j].a1[2]+a[i].a1[3];
									ss=j;
									a[i].d1=3;
									a[i].d=a[i].a1[3];
								}
							}
						}
					}
					if(flag==1)
					{
						ans=s;
						a[ss].d1=3; 
						a[ss].d=a[s1].a1[3];
						s2++;
					}
					if(flag==0)
					{
						s2++;
						ans+=a[i].a1[2];
						a[i].d=a[i].a1[2];
						a[i].d1=2;
					}
				}
				else if(a[i].maxx2==1&&s3<n/2)
				{
					long long int s=0,flag=0,ss;
					for(int j=i-1;j>=1;j--)
					{
						if(a[j].d1==3)
						{
							if(ans-a[j].d+a[j].a1[1]+a[i].a1[3]>ans+a[i].a1[1]) 
							{
								flag=1;
								if(s<ans-a[j].d+a[j].a1[1]+a[i].a1[3])
								{
									s=ans-a[j].d+a[j].a1[1]+a[i].a1[3];
									ss=j;
									a[i].d1=3;
									a[i].d=a[i].a1[3];
								}
							}
						}
					}
					if(flag==1)
					{
						ans=s;
						a[ss].d1=1; 
						a[ss].d=a[s1].a1[1];
						s1++;
					}
					if(flag==0)
					{
						s1++;
						ans+=a[i].a1[1];
						a[i].d=a[i].a1[1];
						a[i].d1=1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
