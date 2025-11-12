#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z;
struct node
{
	int x1,y1,z1,maxn,sum,zero;
}a[1000000];
int cmp(node a,node b)
{
	if(a.zero!=b.zero)return a.zero>b.zero;
	return a.maxn>b.maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].x1>>a[j].y1>>a[j].z1;
			a[j].maxn=max(a[j].x1,max(a[j].y1,a[j].z1));
			if(a[j].x1==0)a[j].zero++;
			if(a[j].y1==0)a[j].zero++;
			if(a[j].z1==0)a[j].zero++;
		}
		sort(a+1,a+1+n,cmp);
		int x=y=z=n/2,ans=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j].maxn==a[j].x1 and x!=0)
			{	
				x--;
				ans+=a[j].x1;
			}
			else if(a[j].maxn==a[j].x1 and x==0)
			{
				if(a[j].y1>=a[j].z1 and y!=0)
				{
					y--;
					ans+=a[j].y1;	
				}
				else if(a[j].y1<=a[j].z1 and z!=0)
				{
					z--;
					ans+=a[j].z1;
				}
			}
			else if(a[j].maxn!=a[j].x1 and x==0)
			{
				if(a[j].maxn==a[j].y1 and y!=0)
				{	
					y--;
					ans+=a[j].y1;
				}
				else if(a[j].maxn==a[j].y1 and y==0)
				{
					z--;
					ans+=a[j].z1;
				}
				else if(a[j].maxn==a[j].z1 and z==0)
				{
					y--;
					ans+=a[j].y1;
				}
				if(a[j].maxn==a[j].z1 and z!=0)
				{
					z--;
					ans+=a[j].z1;
					//cout<<ans<<endl;
				}
				
			}
			else if(a[j].maxn!=a[j].x1 and x!=0)
			{

				if(a[j].maxn==a[j].y1 and y!=0)
				{	
					y--;
					ans+=a[j].y1;
				}
				else if(a[j].maxn==a[j].y1 and y==0)
				{
					z--;
					ans+=a[j].z1;
				}
				else if(a[j].maxn==a[j].z1 and z==0)
				{
					y--;
					ans+=a[j].y1;
				}
				else if(a[j].maxn==a[j].z1 and z!=0)
				{
					z--;
					ans+=a[j].y1;
				}
			}
		}
		cout<<ans<<endl;
	}
	/*
	3
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	2
	10 9 8
	4 0 0	
	*/
	return 0;
 } 
