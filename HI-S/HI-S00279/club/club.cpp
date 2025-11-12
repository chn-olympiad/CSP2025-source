#include<bits/stdc++.h>
using namespace std;
int t,n,maxx,chosen,sum,xs,ys,zs;
struct stu{
	int maxnum,x,y,z,j,k,l;
}a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		chosen=0,sum=0,xs=0,ys=0,zs=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].j=a[i].x-a[i].y-a[i].z;
			a[i].k=a[i].y-a[i].x-a[i].z;
			a[i].l=a[i].z-a[i].x-a[i].y;
			sum+=(a[i].x+a[i].y+a[i].z);
			
			a[i].maxnum=max(a[i].j,max(a[i].k,a[i].l));
		}
		while(chosen < n)
		{
			maxx=-1e9;
			for(int i=1;i<=n;i++)
				maxx=max(maxx,a[i].maxnum);
			for(int i=1;i<=n;i++)
				if(maxx==a[i].maxnum)
				{
					sum+=maxx;
					if(a[i].j==maxx)xs++;
					if(a[i].k==maxx)ys++;
					if(a[i].l==maxx)zs++;
					chosen++;
					a[i].j=-1e9,a[i].k=-1e9,a[i].l=-1e9,a[i].maxnum=-1e9;
					if(xs==n/2)
						for(int m=1;m<=n;m++)
							a[m].j=-1e9,a[m].maxnum=max(a[m].k,a[m].l);
					if(ys==n/2)
						for(int m=1;m<=n;m++)
							a[m].k=-1e9,a[m].maxnum=max(a[m].j,a[m].l);
					if(zs==n/2)
						for(int m=1;m<=n;m++)
							a[m].l=-1e9,a[m].maxnum=max(a[m].j,a[m].k);
				}
		}
		cout<<sum/2<<endl;
	}
	return 0; 
} 
