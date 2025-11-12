#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,w,a[4][1000001],b[10001],c[10001],d[10001];
int maxx[4],vis[4];
int ans=0,o;
struct pp
{
		int id,sum[4],cha;
}q[10001];
bool gz(int x,int y)
{
		return x>y;
}
bool gz2(pp x,pp y)
{
	return x.cha>y.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>w;
	while(w--)
	{
		o=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a[1][i]>>a[2][i]>>a[3][i];
	maxx[1]=max(maxx[1],a[1][i]);
	maxx[2]=max(maxx[2],a[2][i]);
	maxx[3]=max(maxx[3],a[3][i]);
	b[i]=a[1][i];
	c[i]=a[2][i];
	d[i]=a[3][i];
	}
	if(n==2)
	{
		for(int i=1;i<=3;i++)
		{
		 for(int j=1;j<=3;j++)
		 {
		  if(i!=j)
		  o=max(a[i][1]+a[j][2],o);
	  }
	  }
		  cout<<o<<endl;
		  continue;
		}
	if(maxx[2]==0&&maxx[3]==0)
	{
		sort(b+1,b+n+1,gz);
		for(int i=1;i<=n/2;i++)
		o+=b[i];
		cout<<o<<endl;
	}
	if(maxx[1]==0&&maxx[3]==0)
	{
		sort(c+1,c+n+1,gz);
		for(int i=1;i<=n/2;i++)
		o+=c[i];
		cout<<o<<endl;
		continue;
	}
		if(maxx[1]==0&&maxx[2]==0)
	{
		sort(d+1,d+n+1,gz);
		for(int i=1;i<=n/2;i++)
		o+=d[i];
		cout<<o<<endl;
		continue;
	}
}
	return 0;
}
