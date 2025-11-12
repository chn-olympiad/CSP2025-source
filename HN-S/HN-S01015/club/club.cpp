#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
struct node
{
	int x,y,z,id;
}a[N];
struct node0 
{
	int x,id;
}b[N];
struct node1
{
	int y,id;
}c[N];
struct node2
{
	int z,id;
}d[N];
bool cmpb(node0 a,node0 b)
{
	return a.x>b.x;
}
bool cmpc(node1 a,node1 b)
{
	return a.y>b.y;
}
bool cmpd(node2 a,node2 b)
{
	return a.z>b.z;
}
int linshi[5];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T; 
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int m=n/2,lenb=0,lenc=0,lend=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].id=i;
			b[i].x=a[i].x,b[i].id=i,lenb++;
			c[i].y=a[i].y,c[i].id=i,lenc++;
			d[i].z=a[i].z,d[i].id=i,lend++;
		}
		if(n==1)
		{
			int maxn=0;
			for(int i=1;i<=n;i++)maxn=max(max(max(maxn,a[i].x),a[i].y),a[i].z);
			cout<<maxn<<"\n";
			continue;
		}
		if(n==2)
		{
			int sum=0; 
			for(int i=1;i<=n;i++)
			{
				if(i==1)
				{
					int ans=a[1].x+max(a[2].y,a[2].z);
					sum=max(sum,ans);
				}
				else if(i==2)
				{
					int ans=a[1].y+max(a[2].x,a[2].z);
					sum=max(sum,ans);
				}
				else if(i==3) 
				{
					int ans=a[1].z+max(a[2].x,a[2].y);
					sum=max(sum,ans);
				}
			}
			cout<<sum<<"\n";
			continue;
		}
		if(n==3)
		{
			sort(b+1,b+1+lenb,cmpb);
			sort(c+1,c+1+lenc,cmpc);
			sort(d+1,d+1+lend,cmpd);
			cout<<b[1].x+c[1].y+d[1].z<<"\n";
			continue;
		}
		sort(b+1,b+1+lenb,cmpb);
		sort(c+1,c+1+lenc,cmpc);
		sort(d+1,d+1+lend,cmpd);
		int winx=0,winy=0,winz=0;
		for(int i=1;i<=n;i++)
		{
			int maxn=max(max(b[i].x,c[i].y),d[i].z);
			if(b[i].x==maxn)winx++; 
			if(c[i].y==maxn)winy++;
			if(d[i].z==maxn)winz++;
		}
		int maxx=max(max(winx,winy),winz);
		if(maxx==winx)
		{
			int sum=0;
			for(int i=1;i<=m;i++)sum+=b[i].x;
			if(winy>winz)
			{
				for(int i=1;i<m;i++)sum+=c[i].y;
				sum+=d[1].z;
			}
			else
			{
				for(int i=1;i<m;i++)sum+=d[i].z;
				sum+=c[1].y;
			}
			cout<<sum<<"\n";
			continue;
		}
		else if(maxx==winy) 
		{
			int sum=0;
			for(int i=1;i<=m;i++)sum+=c[i].y;
			if(winx>winz)
			{
				for(int i=1;i<m;i++)sum+=b[i].x;
				sum+=d[1].z;
			}
			else
			{
				for(int i=1;i<m;i++)sum+=d[i].z;
				sum+=b[1].x;
			}
			cout<<sum<<"\n";
			continue;
		}
		else if(maxx==winz)
		{
			int sum=0;
			for(int i=1;i<=m;i++)sum+=d[i].z;
			if(winx>winy)
			{
				for(int i=1;i<m;i++)sum+=b[i].x;
				sum+=c[1].y;
			}
			else
			{
				for(int i=1;i<m;i++)sum+=c[i].y;
				sum+=b[1].x;
			}
			cout<<sum<<"\n";
			continue;
		}
	}
	return 0;
}
