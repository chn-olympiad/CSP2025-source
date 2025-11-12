#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,a[100002],b[100002],c[100002],ans;

void doing(int i,int j,int sum,int x,int y,int z,int tmp)
{
	if(i>n)
	{
		if(tmp==1)
			x--;
		if(tmp==2)
			y--;
		if(tmp==3)
			z--;
		if(x>n/2)
			return;
		if(y>n/2)
			return;
		if(z>n/2)
			return;
		ans=max(ans,sum);
		return ;
	}
	if(j==3)
	{
		sum+=c[i];
		doing(i+1,1,sum,x+1,y,z,1);
		doing(i+1,2,sum,x,y+1,z,2);
		doing(i+1,3,sum,x,y,z+1,3);
		return ;
	}
	if(j==2)
	{
		sum+=b[i];
		doing(i+1,1,sum,x+1,y,z,1);
		doing(i+1,2,sum,x,y+1,z,2);
		doing(i+1,3,sum,x,y,z+1,3);
		return ;
	}
	if(j==1)
	{
		sum+=a[i];
		doing(i+1,1,sum,x+1,y,z,1);
		doing(i+1,2,sum,x,y+1,z,2);
		doing(i+1,3,sum,x,y,z+1,3);
		return ;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		a[0]=0,b[0]=0,c[0]=0;
		doing(0,1,0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
