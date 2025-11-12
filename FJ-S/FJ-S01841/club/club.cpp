#include<bits/stdc++.h>
using namespace std;
int t,n,ans[5],rans[5];
struct node
{
	int x,y,z,xx,yy,zz;
}a[100005];
bool cmp(node a,node b)
{
	if(a.x-a.y==b.x-b.y)
		return a.y-a.z>b.y-b.z;
	return a.x-a.y>b.x-b.y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans[1]=ans[2]=ans[3]=rans[1]=rans[2]=rans[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].xx=1,a[i].yy=2,a[i].zz=3;
			if(a[i].x<a[i].y)
				swap(a[i].x,a[i].y),swap(a[i].xx,a[i].yy);
			if(a[i].x<a[i].z)
				swap(a[i].x,a[i].z),swap(a[i].xx,a[i].zz);
			if(a[i].y<a[i].z)
				swap(a[i].y,a[i].z),swap(a[i].yy,a[i].zz);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(ans[a[i].xx]+1<=n/2)
			{
				ans[a[i].xx]++;
				rans[a[i].xx]+=a[i].x;
			}
			else if(ans[a[i].yy]+1<=n/2)
			{
				ans[a[i].yy]++;
				rans[a[i].yy]+=a[i].y;
			}
			else
			{
				ans[a[i].zz]++;
				rans[a[i].zz]+=a[i].z;
			}
		}
		cout<<rans[1]+rans[2]+rans[3]<<endl;
	}
	return 0;
}
