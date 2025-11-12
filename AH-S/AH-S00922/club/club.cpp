#include<bits/stdc++.h>
using namespace std;
int t,n;
long long int ans;
int mi[100009][5],sum[5];
struct abc
{
	int x,y,z;
	int n1,n2,n3;
}a[100009];
bool cmp(abc aa,abc bb)
{
	if(aa.n1==bb.n1)
	{
		return aa.n2>bb.n2;//zheli
	}
	else if(aa.n2==bb.n2)
	{
		return aa.n3>=bb.n3;//zheli
	}
	return aa.n1>bb.n1;//zheli
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
		ans=0;
		memset(sum,0,sizeof(sum));
		memset(mi,0,sizeof(mi));
		for(int i=1;i<=n;i++)
		{
			a[i].x=a[i].y=a[i].z=0;
		}
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
			{
				a[i].n1=a[i].x;
				mi[i][1]=1;
				if(a[i].y>=a[i].z){mi[i][2]=2;mi[i][3]=3;a[i].n2=a[i].y;	a[i].n3=a[i].z;}
				else 	{mi[i][2]=3;mi[i][3]=2;a[i].n2=a[i].z; a[i].n3=a[i].y;}
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
			{
				a[i].n1=a[i].y;
				mi[i][1]=2;
				if(a[i].x>=a[i].z)	{mi[i][2]=1;mi[i][3]=3;a[i].n2=a[i].x; a[i].n3=a[i].z;}
				else 	{mi[i][2]=3;mi[i][3]=1;a[i].n2=a[i].z; a[i].n3=a[i].x;}
			}
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y)
			{
				a[i].n1=a[i].z;
				mi[i][1]=3;
				if(a[i].y>=a[i].x){mi[i][2]=2;mi[i][3]=1;	a[i].n2=a[i].y;	a[i].n3=a[i].x;}
				else 	{mi[i][2]=1;mi[i][3]=2;a[i].n2=a[i].x; a[i].n3=a[i].y;}			
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(sum[mi[i][1]]<n/2)
			{
				sum[mi[i][1]]++;
				ans+=a[i].n1;
			}
			else if(sum[mi[i][2]]<n/2)
			{
				sum[mi[i][2]]++;
				ans+=a[i].n2;
			}
			else if(sum[mi[i][3]]<n/2)
			{
				sum[mi[i][3]]++;
				ans+=a[i].n3;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}




