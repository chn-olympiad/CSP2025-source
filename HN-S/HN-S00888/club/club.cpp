#include<bits/stdc++.h>
using namespace std;
int n;
struct nodea
{
	int a,b,c;
	bool operator <(const nodea &f) const
	{
		return a-max(b,c)>f.a-max(f.b,f.c);
	}
};
struct nodeb
{
	int a,b,c;
	bool operator <(const nodeb &f) const
	{
		return b-max(a,c)>f.b-max(f.a,f.c);
	}
};
struct nodec
{
	int a,b,c;
	bool operator <(const nodec &f) const
	{
		return c-max(b,a)>f.c-max(f.b,f.a);
	}
};
priority_queue<nodea> a;
priority_queue<nodeb> b;
priority_queue<nodec> c;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int aa,bb,cc;
			cin>>aa>>bb>>cc;
			if(aa>=max(bb,cc)) a.push({aa,bb,cc});
			else if(bb>=max(aa,cc)) b.push({aa,bb,cc});
			else c.push({aa,bb,cc});
		}
		while((int)a.size()>n/2)
		{
			nodea x=a.top();
			if(x.b>=x.c) b.push({x.a,x.b,x.c});
			else c.push({x.a,x.b,x.c});
			a.pop();
		}
		while((int)b.size()>n/2)
		{
			nodeb x=b.top();
			if(x.a>=x.c) a.push({x.a,x.b,x.c});
			else c.push({x.a,x.b,x.c});
			b.pop();
		}
		while((int)c.size()>n/2)
		{
			nodec x=c.top();
			if(x.a>=x.b) a.push({x.a,x.b,x.c});
			else b.push({x.a,x.b,x.c});
			c.pop();
		}
		long long ans=0;
		while(a.size()) ans+=a.top().a,a.pop();
		while(b.size()) ans+=b.top().b,b.pop();
		while(c.size()) ans+=c.top().c,c.pop();
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
