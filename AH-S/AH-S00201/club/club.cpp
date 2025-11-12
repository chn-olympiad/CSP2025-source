#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,y,z,t;
} a[100005];
int xx[100005],yy[100005],zz[100005];
bool cmp(int x,int y)
{
	return a[x].t>a[y].t;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tttt;
	cin>>tttt;
	while(tttt--)
	{
		int n,c1=0,c2=0,c3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			int s=x+y+z;
			a[i].x=max(max(x,y),z);
			a[i].z=min(min(x,y),z);
			a[i].y=s-a[i].x-a[i].z;
			a[i].t=a[i].x-a[i].y;
			if(x==a[i].x)  xx[++c1]=i;
			else  if(y==a[i].x) yy[++c2]=i;
			else  zz[++c3]=i;
			ans+=a[i].x;
			//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<ans<<"\n";
		}
		//cout<<ans<<" ";
		sort(xx+1,xx+c1+1,cmp);
		sort(yy+1,yy+c2+1,cmp);
		sort(zz+1,zz+c3+1,cmp);
		while(c1>n/2)
		{
			ans-=a[xx[c1--]].t;
		}
		while(c2>n/2)
		{
			ans-=a[yy[c2--]].t;
		}
		while(c3>n/2)
		{
			ans-=a[zz[c3--]].t;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
