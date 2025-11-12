#include<bits/stdc++.h>
using namespace std;
struct STU
{
	int a,b,c;
} s[100005];

struct ___
{
	int num;
	int c;
	bool operator < (const ___ &a) const
	{
		return c > a.c;
	}
};
priority_queue<___> q;
int w[5][100005],x,y,z;
bool vis[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		long long ans=0;
		cin>>n;
		m=n/2;
		x=y=z=0;
		while(!q.empty()) q.pop();
		for(int i=1; i<=n; i++) vis[i]=false;
		for(int i=1; i<=n; i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c)
			{
				w[1][++x]=i;
				ans+=s[i].a;
			}
			else if(s[i].b>=s[i].a&&s[i].b>=s[i].c)
			{
				w[2][++y]=i;
				ans+=s[i].b;
			}
			else
			{
				w[3][++z]=i;
				ans+=s[i].c;
			}
		}
		if(x<=m&&y<=m&&z<=m) cout<<ans<<'\n';
		else
		{
			int o;
			if(x>m)
			{
				o=x-m;
				for(int i=1; i<=x; i++)
				{
					int k=w[1][i];
					q.push((___){k,s[k].a-s[k].b});
					q.push((___){k,s[k].a-s[k].c});
				}
			}
			else if(y>m)
			{
				o=y-m;
				for(int i=1; i<=y; i++)
				{
					int k=w[2][i];
					q.push((___){k,s[k].b-s[k].a});
					q.push((___){k,s[k].b-s[k].c});
				}
			}
			else
			{
				o=z-m;
				for(int i=1; i<=z; i++)
				{
					int k=w[3][i];
					q.push((___){k,s[k].c-s[k].b});
					q.push((___){k,s[k].c-s[k].a});
				}
			}
			while(o--)
			{
				if(vis[q.top().num])
				{
					o++;
					q.pop();
					continue;
				}
				ans-=q.top().c;
				vis[q.top().num]=true;
				q.pop();
			}
			cout<<ans<<'\n';
		}

	}
	return 0;
}
