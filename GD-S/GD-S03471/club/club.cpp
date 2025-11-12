//Author: mairuisheng
//#pragma GCC optimize(3)
#include<cstdio>
#include<queue>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char s;
	s=getchar();
	while(s<48||s>57)
	{
		if(s=='-')f=-f;
		s=getchar();
	}
	while(s>47&&s<58)
	{
		x=(x<<3)+(x<<1)+s-48;
		s=getchar();
	}
	return x*f;
}
constexpr int N=1e5+1;
int n,lmt;
int a[N][4];
priority_queue<int,vector<int>,greater<int> > q,q2,q3;
void Solve()
{
	while(!q.empty())q.pop();
	while(!q2.empty())q2.pop();
	while(!q3.empty())q3.pop();
	n=read();
	lmt=n>>1ll;
	int i,ans=0;
	int cnt[3];
	cnt[0]=cnt[1]=cnt[2]=0;
	for(i=1;i<=n;++i)
	{
		a[i][0]=read();
		a[i][1]=read();
		a[i][2]=read();
		a[i][3]=max(a[i][0],max(a[i][1],a[i][2]));
		a[i][3]=a[i][0]+a[i][1]+a[i][2]-a[i][3]-min(a[i][0],min(a[i][1],a[i][2]));
	}
	for(i=1;i<=n;++i)
	{
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
		{
			ans+=a[i][0];
			q.push(a[i][0]-a[i][3]);
			if(cnt[0]==lmt)
			{
				ans-=q.top();
				q.pop();
			}
			else ++cnt[0];
		}
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])
		{
			ans+=a[i][1];
			q2.push(a[i][1]-a[i][3]);
			if(cnt[1]==lmt)
			{
				ans-=q2.top();
				q2.pop();
			}
			else ++cnt[1];
		}
		else
		{
			ans+=a[i][2];
			q3.push(a[i][2]-a[i][3]);
			if(cnt[2]==lmt)
			{
				ans-=q3.top();
				q3.pop();
			}
			else ++cnt[2];
		}
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	T=read();
	while(T--)Solve();
	return 0;
}

