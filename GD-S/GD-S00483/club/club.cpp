#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+9;
const int N1=205;
int Q,n;
ll f[2][N1][N1][N1];
int a[N][4];
priority_queue<ll,vector<ll>,greater<ll> >q;
priority_queue<ll>q2;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&Q);
	while(Q--)
	{
		bool suba=1,subb=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][2]!=0||a[i][3]!=0)suba=0;
				if(a[i][3]!=0)subb=0;
			}
		}
		if(suba)
		{
			while(!q.empty())q.pop();
			ll tot=0,ans=0;
			for(int i=1;i<=n;i++)
			{
				if(tot<n/2)
				{
					tot++;
					ans+=a[i][1];
					q.push(a[i][1]);
				}
				else 
				{
					if(a[i][1]>q.top())
					{
						ans-=q.top();
						q.pop();
						ans+=a[i][1];
						q.push(a[i][1]);
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		if(n<=200)
		{
			ll ans=0;
			for(int i=1;i<=n;i++)
			{
				ll now=i&1,las=now^1;
				for(int j=0;j<=min(i,n/2);j++)
				{
					for(int k=0;k<=min(i-j,n/2);k++)
					{
						ll l=i-j-k;
						if(l<0||l>n/2)continue;
						f[now][j][k][l]=0;
					}
				}
				for(int j=0;j<=min(i,n/2);j++)
				{
					for(int k=0;k<=min(i-j,n/2);k++)
					{
						ll l=i-j-k;
						if(l<0||l>n/2)continue;
					//	cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
						if(j)f[now][j][k][l]=max(f[now][j][k][l],f[las][j-1][k][l]+a[i][1]);
						if(k)f[now][j][k][l]=max(f[now][j][k][l],f[las][j][k-1][l]+a[i][2]);
						if(l)f[now][j][k][l]=max(f[now][j][k][l],f[las][j][k][l-1]+a[i][3]);
						ans=max(ans,f[now][j][k][l]);
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		if(subb)
		{
			while(!q2.empty())q2.pop();
			ll ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=a[i][1];
				q2.push(a[i][2]-a[i][1]);
			}
			for(int i=1;i<=n/2;i++)
			{
				ans+=q2.top();
				q2.pop();
			}
			printf("%lld\n",ans);
			continue;
		}
	}
	return 0;
}
