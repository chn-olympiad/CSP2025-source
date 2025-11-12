#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1;
struct mem{
	int a[3],b[3];
	mem()
	{
		a[0]=a[1]=a[2]=b[0]=0,b[1]=1,b[2]=2;
	}
	void sorts()
	{
		if(a[b[0]]<a[b[1]])swap(b[0],b[1]);
		if(a[b[1]]<a[b[2]])swap(b[1],b[2]);
		if(a[b[0]]<a[b[1]])swap(b[0],b[1]);
	}
	int calc(int x,int y)
	{
		return a[b[y]]-a[b[x]];
	}
}a[N];
struct club{
	int a[N],siz;
	void push(int x)
	{
		a[++siz]=x;
	}
}c[3];
int t,n,p,ans;
bool cmp(int x,int y)
{
	return a[x].calc(0,1)<a[y].calc(0,1);
}
bool ccmp(int x,int y)
{
	return a[x].calc(1,2)<a[y].calc(1,2);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=c[0].siz=c[1].siz=c[2].siz=0;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i].a[0]>>a[i].a[1]>>a[i].a[2];
			a[i].sorts();
			ans+=a[i].a[a[i].b[0]];
			c[a[i].b[0]].push(i);
		}
		if(c[0].siz>n/2)p=0;
		else if(c[1].siz>n/2)p=1;
		else if(c[2].siz>n/2)p=2;
		else p=-1;
		if(~p)
		{
			sort(c[p].a+1,c[p].a+1+c[p].siz,cmp);
			for(int i=n/2+1,x;i<=c[p].siz;++i)
			{
				x=c[p].a[i];
				c[a[x].b[1]].push(x),ans+=a[x].a[a[x].b[1]]-a[x].a[a[x].b[0]];
			}
			c[p].siz=n/2;
			if(c[0].siz>n/2)p=0;
			else if(c[1].siz>n/2)p=1;
			else if(c[2].siz>n/2)p=2;
			else p=-1;
			if(~p)
			{
				sort(c[p].a+1,c[p].a+1+c[p].siz,ccmp);
				for(int i=n/2+1,x;i<=c[p].siz;++i)
				{
					x=c[p].a[i];
					c[a[x].b[2]].push(x),ans+=a[x].a[a[x].b[2]]-a[x].a[a[x].b[1]];
				}
			}
		}
		cout<<ans<<'\n';
	}
}
