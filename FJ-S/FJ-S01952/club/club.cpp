#include<bits/stdc++.h>
using namespace std;
int n,m,b[100001][4],c[4];
struct pp
{
	int x,y,z,e;
}a[100001];
int cmp1(pp l,pp r)
{
	l.e=max(l.x,max(l.y,l.z));
	r.e=max(r.x,max(r.y,r.z));
	return l.e>r.e;
}
int cmp(pp l,pp r)
{
	l.e=max(l.x,max(l.y,l.z))*3-l.x-l.y-l.z;
	r.e=max(r.x,max(r.y,r.z))*3-r.x-r.y-r.z;
	return l.e>r.e;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		c[1]=0;
		c[2]=0;
		c[3]=0;
		memset(b,0,sizeof(b));
		cin>>n;
		int s=0;
		for(int i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp1);
		sort(a+1,a+n+1,cmp);
		int u=0,v=0,w=0;
		for(int i=1;i<=n;i++)
		{
			int k=s;
			if(u>=n/2)
				s+=max(a[i].y,a[i].z);
			if(v>=n/2)
				s+=max(a[i].x,a[i].z);
			if(w>=n/2)
				s+=max(a[i].y,a[i].x);
			if(u<n/2&&v<n/2&&w<n/2)
				s+=max(a[i].x,max(a[i].y,a[i].z));
			if(s-k==a[i].x)
				u++;
			if(s-k==a[i].y)
				v++;
			if(s-k==a[i].z)
				w++;
		}
		cout<<s<<"\n";
	}
	return 0;
}
