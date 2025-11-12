#include <bits/stdc++.h>
using namespace std;
//#define int long long
int a[500005];
struct b
{
	int w;
	int a;
}
c[500005];
bool cmp(b &x,b &y)
{
	if(x.a!=y.a)
	{
		return x.a<y.a;
	}
	return x.w<y.w;
}
int dy[500005],dp[500005];
map<int,int> m;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,xx,w;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		c[i].w=i;
		c[i].a=c[i-1].a^a[i];
	}
	sort(c+1,c+n+1,cmp);
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<c[i].a<<' '<<c[i].w<<endl;
	}
	*/
	m[c[1].a]=1;
	for(int i=2;i<=n;i++)
	{
		if(c[i].a!=c[i-1].a)
			m[c[i].a]=i;
	}
	map<int,int>::iterator it=m.begin();
	/*
	while(it!=m.end())
	{
		cout<<it->first<<' '<<it->second<<endl;
		it++;
	}
	*/
	memset(dy,-1,sizeof(dy));
	dy[0]=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			xx=(c[i].a^k);
			it=m.find(xx);
			//cout<<xx<<' '<<it->first<<' '<<it->second<<endl;
			//cout<<(it==m.end())<<' ';
			if(it!=m.end())
			{
				w=it->second;
				if(c[w++].w<c[i].w)
				{
					while(c[w].w<c[i].w && c[w].a==xx)w++;
					dy[c[w-1].w]=c[i].w;
				}
			}
			if(!xx)
				dy[0]=min(dy[0],c[i].w);
		}
		if(dy[0]!=INT_MAX)
			dp[dy[0]+1]=1;
		//cout<<dy[0]<<' ';
		for(int i=1;i<=n;i++)
		{
			//cout<<dy[i]<<endl;
			dp[i]=max(dp[i],dp[i-1]);
			if(dy[i]!=-1)
				dp[dy[i]+1]=max(dp[dy[i]+1],dp[i]+1);
			//cout<<c[i].a<<' '<<dp[i]<<endl;
		}
		cout<<max(dp[n],dp[n+1]);
	return 0;
}
/*
4 2
2 1 0 3
*/
