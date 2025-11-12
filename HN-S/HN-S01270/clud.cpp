#include<bits/stdc++.h>
using namespace std;
int t,n,yh,rh,sh,z,m[100005];
struct a
{
	int a1,a2,a3,a4;
}r[100005];
int comp(a b,a c)
{
	return b.a1>c.a1;
}
int cmp(a b,a c)
{
	return b.a2>c.a2;
}

int main()
{
	freopen("clud.in","r",strin);
	freopen("clud.out"."w",stdout);
	cin>>t;
	for(int w=1;w<=t;w++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>r[i].a1>>r[i].a2>>r[i].a3;
		}
		sort(r+1,r+n+1,comp);
		for(int i=1;i<=n;i++)
		{
			if(r[i].a1>r[i].a2&&r[i].a1>r[i].a3&&yh<n/2&&r[i].a4==0)
			{
				yh++;
				z+=r[i].a1;
				r[i].a4=1;
			}
		}
		sort(r+1,r+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(r[i].a2>r[i].a3 && rh<n/2 && r[i].a4==0)
			{
				rh++;
				z+=r[i].a2;
			
				r[i].a4=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(r[i].a4==0)
			{
				z+=r[i].a3;
			
			}
				
				
			
		}
		cout<<z<<endl;
		yh=0;
		rh=0;
		memset(r,0,sizeof(r));
		z=0;
	}
}
