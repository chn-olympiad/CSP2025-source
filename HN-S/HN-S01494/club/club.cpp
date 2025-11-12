#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,z;
}a[100005];
int abm[50005],bbm[50005],cbm[50005];
int main()
{
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int n,as=0,bs=0,cs=0,cnt=0;
 		cin>>n;
 		for(int i=1;i<=n;i++)
 		cin>>a[i].x>>a[i].y>>a[i].z;
 		for(int i=1;i<=n;i++)
 		{
 			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x)
 			{
 				if(as<n/2)
 				{
 					cnt+=a[i].x;
 					abm[as+1]=i;
 					as++;
				}
				else
				{
					bool h=1;
					for(int j=1;j<=as;j++)
					{
						if(a[i].x-a[abm[j]].x-a[i].y+a[abm[j]].y)
						{
							if(bs<n/2)
							{
								cnt=cnt+a[i].x-a[abm[j]].x-a[i].y+a[abm[j]].y;
								bbm[bs+1]=j;
								abm[as+1]=i;
								h=0;
								break;
							}
						}
						if(a[i].x-a[abm[j]].x-a[i].z+a[abm[j]].z)
						{
							if(cs<n/2)
							{
								cnt=cnt+a[i].x-a[abm[j]].x-a[i].z+a[abm[j]].z;
								cbm[cs+1]=j;
								abm[as+1]=i;
								h=0;
								break;
							}
						}
					}
					if(!h)
					{
						if(a[i].y>a[i].z && bs<n/2)
		 				{
		 					cnt+=a[i].y;
		 					bbm[bs+1]=i;
		 					bs++;
						}
						else
						{
							cnt+=a[i].z;
							cbm[cs+1]=i;
							cs++;
						}
					}
				}
			}
			else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y)
 			{
 				if(bs<n/2)
 				{
 					cnt+=a[i].y;
 					bbm[bs+1]=i;
 					bs++;
				}
 				else
				{
					bool h=1;
					for(int j=1;j<=bs;j++)
					{
						if(a[i].y-a[bbm[j]].y-a[i].x+a[bbm[j]].x)
						{
							if(as<n/2)
							{
								cnt=cnt+a[i].y-a[bbm[j]].y-a[i].x+a[bbm[j]].x;
								bbm[bs+1]=i;
								abm[as+1]=j;
								h=0;
								break;
							}
						}
						if(a[i].y-a[bbm[j]].y-a[i].z+a[bbm[j]].z)
						{
							if(cs<n/2)
							{
								cnt=cnt+a[i].y-a[bbm[j]].y-a[i].z+a[bbm[j]].z;
								cbm[cs+1]=j;
								bbm[bs+1]=i;
								h=0;
								break;
							}
						}
					}
					if(!h)
					{
						if(a[i].x>a[i].z && as<n/2)
		 				{
		 					cnt+=a[i].x;
		 					abm[as+1]=i;
		 					as++;
						}
						else
						{
							cnt+=a[i].z;
							cbm[cs+1]=i;
							cs++;
						}
					}
				}
			}
			else
			{
				if(cs<n/2)
 				{
 					cnt+=a[i].z;
 					cbm[cs+1]=i;
 					cs++;
				}
 				else
				{
					bool h=1;
					for(int j=1;j<=cs;j++)
					{
						if(a[i].z-a[cbm[j]].z-a[i].x+a[cbm[j]].x)
						{
							if(as<n/2)
							{
								cnt=cnt+a[i].z-a[cbm[j]].z-a[i].x+a[cbm[j]].x;
								cbm[cs+1]=i;
								abm[as+1]=j;
								h=0;
								break;
							}
						}
						if(a[i].z-a[abm[j]].z-a[i].y+a[abm[j]].y)
						{
							if(bs<n/2)
							{
								cnt=cnt+a[i].z-a[abm[j]].z-a[i].y+a[abm[j]].y;
								cbm[cs+1]=i;
								bbm[bs+1]=j;
								h=0;
								break;
							}
						}
					}
					if(!h)
					{
						if(a[i].x>a[i].y && as<n/2)
		 				{
		 					cnt+=a[i].x;
		 					abm[as+1]=i;
		 					as++;
						}
						else
						{
							cnt+=a[i].y;
							bbm[bs+1]=i;
							bs++;
						}
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
