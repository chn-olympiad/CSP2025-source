#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x1,x2,x3;
}p1[100011],p2[100011],p3[100011];
int t;
bool cmp1(node a,node b)
{
	if(a.x1<b.x1) return 1;
	return 0;
}
bool cmp2(node a,node b)
{
	if(a.x2<b.x2) return 1;
	return 0;
}
bool cmp3(node a,node b)
{
	if(a.x3<b.x3) return 1;
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
		int n,k1=0,k2=0,k3=0;
		long long val=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b && a>=c)
			{
				p1[++k1].x1=a;
				p1[k1].x2=b;
				p1[k1].x3=c;
				val+=a;
				continue;
			}
			if(b>=a && b>=c)
			{
				p2[++k2].x1=a;
				p2[k2].x2=b;
				p2[k2].x3=c;
				val+=b;
				continue;
			}
			if(c>=a && c>=b)
			{
				p3[++k3].x1=a;
				p3[k3].x2=b;
				p3[k3].x3=c;
				val+=c;
				continue;
			}
		}
		sort(p1+1,p1+k1+1,cmp1);
		sort(p2+1,p2+k2+1,cmp2);
		sort(p3+1,p3+k3+1,cmp3);
		long long zz[100011];
		if(k1>n/2)
		{
			for(int i=1;i<=k1;i++) zz[i]=max(p1[i].x2,p1[i].x3)-p1[i].x1;
			sort(zz+1,zz+k1+1);
			for(int i=k1;i>n/2;i--) val+=zz[i];
		}
		else
		{
			if(k2>n/2)
			{
				for(int i=1;i<=k2;i++) zz[i]=max(p2[i].x1,p2[i].x3)-p2[i].x2;
				sort(zz+1,zz+k2+1);
				for(int i=k2;i>n/2;i--) val+=zz[i];
			}
			else
			{
				if(k3>n/2)
				{
					for(int i=1;i<=k3;i++) zz[i]=max(p3[i].x1,p3[i].x2)-p3[i].x3;
					sort(zz+1,zz+k3+1);
					for(int i=k3;i>n/2;i--) val+=zz[i];
				}
			}
		}
		cout<<val<<'\n';
	}
	return 0;
}
