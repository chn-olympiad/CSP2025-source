#include<bits/stdc++.h>
using namespace std;
int t,n,m;
struct node
{
	int x,y,z;
}a[100005];
bool cmp1(node a,node b)
{
	return a.x>b.x;
};
bool cmp2(node a,node b)
{
	return a.y>b.y;
};
bool cmp3(node a,node b)
{
	return a.z>b.z;
};
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n/2;i++)
		{
			ans+=a[i].x;	
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n/2;i++)
		{
			ans+=a[i].y;	
		}
		sort(a+1,a+1+n,cmp3);
		for(int i=1;i<=n/2;i++)
		{
			ans+=a[i].z;	
		}
		cout<<ans<<endl;
	}
	return 0;
}


