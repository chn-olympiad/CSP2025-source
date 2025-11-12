#include<bits/stdc++.h>
using namespace std;

struct node{
	int l,r,p;
}a[1000005];

bool px(node a,node b)
{
	return a.p>b.p;
}

int b[10004];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[i].l=x;
			a[i].r=y;
			a[i].p=z;
		}
		sort(a,a+m,px);
		int d=0,ans=0;
		for(int i=0;i<m;i++)
		{
			if(b[a[i].l]<2&&b[a[i].r]<2)
			{
				b[a[i].l]++;
				b[a[i].r]++;
				d++;
				ans+=a[i].p;
			}
			if(d==n-1)
			{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
