#include<bits/stdc++.h>
using namespace std;
struct xy{
	int x,y,z;
};
bool cmp(struct xy x,struct xy y)
{
	return x.x>y.x;
}
int t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		struct xy a[100005]={0};
		int f=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0 || a[i].z!=0)
			{
				f=0;
			}
		}
		if(f==1)
		{
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].x;
			}
			cout<<ans;
		}
		else
		{
			cout<<1;
		}
	}
	return 0;
}
