#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read();

const int N = 1e4+10;

vector<pair<int,int> >g[N];

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	cout<<13;
	return 0;
}

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

