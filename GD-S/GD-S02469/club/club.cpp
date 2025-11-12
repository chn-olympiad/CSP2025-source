#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int T,n,b[10],p[N];
int sum[4];
bool vis[N];
struct node
{
	int n1,n2,n3;
}a[N];
struct TT
{
	int idx,k,d;
	bool operator < (const TT& x) const 
	{
		return x.k>k;
	}
}mini[4];
struct I
{
	int x;
	bool operator < (const I& X) const
	{
		return X.x>x;
	}
};
priority_queue<TT>q;
priority_queue<I>qq[4];
void cmp(TT u)
{
	if(mini[u.d].k>=u.k)
	{
		mini[u.d]=u;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		sum[1]=sum[2]=sum[3]=0;
		while(!qq[1].empty())
		{qq[1].pop();
		}
		while(!qq[2].empty())
		{qq[2].pop();
		}
		while(!qq[3].empty())
		{qq[3].pop();
		}
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			vis[i]=false;
			scanf("%lld%lld%lld",&a[i].n1,&a[i].n2,&a[i].n3);
			q.push({i,a[i].n1,1});
			q.push({i,a[i].n2,2});
			q.push({i,a[i].n3,3});
			b[1]=a[i].n1;
			b[2]=a[i].n2;
			b[3]=a[i].n3;
			sort(b+1,b+1+3);
			p[i]=b[2]-b[3];
		}
		int ans=0;
		while(!q.empty())
		{
			TT u=q.top();
			q.pop();
			if(vis[u.idx])
			{
				continue;
			}
			if(sum[u.d]==(n>>1))
			{
				I tmp=qq[u.d].top();
				if(u.k+tmp.x>=0)
				{
					ans+=u.k+tmp.x;
					vis[u.idx]=true;
					qq[u.d].pop();
					qq[u.d].push((I){p[u.idx]
					});
				}
			}
			else
			{
				ans+=u.k;
				sum[u.d]++;
				qq[u.d].push((I){p[u.idx]
					});
				vis[u.idx]=true;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
