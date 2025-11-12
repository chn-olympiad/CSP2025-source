#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
int az=0,bz=0,cz=0;
int b[5][100005],dz[5];
long long ans=0;
int max(int x,int y)
{
	return (x>y)?x:y;
}
int min(int x,int y)
{
	return (x<y)?x:y;
}
int max(int x,int y,int z)
{
	return max(max(x,y),z);
}
int min(int x,int y,int z)
{
	return min(min(x,y),z);
}
int cmx(int x,int y,int z)
{
	return x+y+z-max(x,y,z)-min(x,y,z);

}

int mainn()
{

	cin>>n;
	az=0;bz=0;cz=0;
	dz[1]=0;dz[2]=0;dz[3]=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		int mx=max(x,y,z);
		int cm=cmx(x,y,z);
		if(mx==x)
		{
			ans+=x;
			az++;
			dz[1]++;
			b[1][dz[1]]=mx-cm;
		}
		else if(mx==y)
		{
			ans+=y;
			bz++;
			dz[2]++;
			b[2][dz[2]]=mx-cm;
		}
		else if(mx==z)
		{
			ans+=z;
			cz++;
			dz[3]++;
			b[3][dz[3]]=mx-cm;
		}
		else cout<<"error";
	}
	if(az>n/2)
	{
		sort(b[1]+1,b[1]+dz[1]+1);
		for(int i=1;i<=az-n/2;i++)
		{
			ans-=b[1][i];
		}
	}
	else if(bz>n/2)
	{
		sort(b[2]+1,b[2]+dz[2]+1);
		for(int i=1;i<=bz-n/2;i++)
		{
			ans-=b[2][i];
		}
	}
	else if(cz>n/2)
	{
		sort(b[3]+1,b[3]+dz[3]+1);
		for(int i=1;i<=cz-n/2;i++)
		{
			ans-=b[3][i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		mainn();
	}
	return 0;
}
