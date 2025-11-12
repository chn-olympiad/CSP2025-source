#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T, n, a[N][4];
struct node
{
	int v, id;
}b[N][4];
bool cmp(node x, node y)
{
	if(x.v==y.v)
	{
		return x.id<y.id;
	}
	return x.v>y.v;
}
int f[N], s[N], t[N], now[N], r[N], diff[N], diff1[N];
struct bo
{
	int y, id;
}c1[N], c2[N], c3[N];
bool cmp1(bo x, bo y)
{
	return diff[x.id]>diff[y.id];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>T;T;T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			now[i]=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i][1].v=a[i][1];
			b[i][2].v=a[i][2];
			b[i][3].v=a[i][3];
			b[i][1].id=1,b[i][2].id=2,b[i][3].id=3;
		}
		for(int i=1;i<=n;i++)
		{
			sort(b[i]+1,b[i]+1+3,cmp);
			f[i]=b[i][1].id,s[i]=b[i][2].id,t[i]=b[i][3].id;
			diff[i]=b[i][1].v-b[i][2].v;
			diff1[i]=b[i][2].v-b[i][3].v;
		}
		int cnt=0, cnt1=0, cnt2=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==1)
			{
				c1[++cnt].y=a[i][1];
				c1[cnt].id=i;
			}
			else if(f[i]==2)
			{
				c2[++cnt1].y=a[i][2];
				c2[cnt1].id=i;
			}
			else if(f[i]==3)
			{
				c3[++cnt2].y=a[i][3];
				c3[cnt2].id=i;
			}
		}
		sort(c1+1,c1+1+cnt,cmp1);
		sort(c2+1,c2+1+cnt1,cmp1);
		sort(c3+1,c3+1+cnt2,cmp1);
		if(cnt>n/2)
		{
			for(int i=n/2+1;i<=cnt;i++)
			{
				now[i]=1;
				if(s[c1[i].id]==2)
				{
					c2[++cnt1].y=a[c1[i].id][2];
					c2[cnt1].id=c1[i].id;
				}
				else
				{
					c3[++cnt2].y=a[c1[i].id][3];
					c3[cnt2].id=c1[i].id;
				}
			}
			cnt=n/2;
		}
		else if(cnt1>n/2)
		{
			for(int i=n/2+1;i<=cnt1;i++)
			{
				now[i]=1;
				if(s[c2[i].id]==1)
				{
					c1[++cnt].y=a[c2[i].id][1];
					c1[cnt].id=c2[i].id;
				}
				else
				{
					c3[++cnt2].y=a[c2[i].id][3];
					c3[cnt2].id=c2[i].id;
				}
			}
			cnt1=n/2;
		}
		else if(cnt2>n/2)
		{
			for(int i=n/2+1;i<=cnt2;i++)
			{
				if(s[c3[i].id]==1)
				{
					c1[++cnt].y=a[c3[i].id][1];
					c1[cnt].id=c3[i].id;
				}
				else
				{
					c2[++cnt1].y=a[c3[i].id][2];
					c2[cnt1].id=c3[i].id;
				}
			}
			cnt2=n/2;
		}
		int ans=0;
		for(int i=1;i<=cnt;i++)
		{
			ans+=c1[i].y;
		}
		for(int i=1;i<=cnt1;i++)
		{
			ans+=c2[i].y;
		}
		for(int i=1;i<=cnt2;i++)
		{
			ans+=c3[i].y;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

