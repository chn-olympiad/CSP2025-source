#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int N2=1e4+10;
struct yi
{
	int u,v,w;
};
yi bo[N];
bool operator < (const yi& x,const yi& y)
{
	return x.w<y.w;
}
bool operator > (const yi& x,const yi& y)
{
	return x.w>y.w;
}
priority_queue<yi,vector<yi>,greater<yi> >sh;
struct er
{
	int c;
	int a[N2];
}sh2[20];
int n,m,k;
int f[N];
int check(int x)
{
	if(f[x]==x) return x;
	f[x]=check(f[x]);
	return f[x];
}
int prm(int c)
{
		for(int i=1;i<=c;i++)
		{
			f[i]=i;
		}
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			if(c==1) break;
			yi x;
			x=sh.top();
			sh.pop();
			if(check(x.u)!=check(x.v))
			{
				c--;
				ans+=x.w;
				f[check(x.u)]=check(x.v);
			}
		}
		return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		cin >> bo[i].u >> bo[i].v >> bo[i].w;
		sh.push(bo[i]);
	}
	for(int i=1;i<=k;i++)
	{
		cin >> sh2[i].c;
		for(int j=1;j<=n;j++)
		{
			cin >> sh2[i].a[j];
		}
	}
	if(k==0)
	{	
		cout << prm(n);
		return 0;
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				yi x;x.w=sh2[i].a[j];
				x.u=j;x.v=n+i;
				sh.push(x);
			}
		}
		cout << prm(n+k);
	}
	return 0;
}
