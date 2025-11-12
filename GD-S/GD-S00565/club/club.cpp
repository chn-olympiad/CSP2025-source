#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll n,T,g[4][maxn],g_[4],ans;
struct node
{
	ll a[4],id;
	ll u,v;
}s[maxn];
bool cmp(ll a,ll b)
{
	return (s[a].a[s[a].u]-s[a].a[s[a].v])>(s[b].a[s[b].u]-s[b].a[s[b].v]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		for(int i=1;i<=3;i++) g_[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			s[i].id=i;
			cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
			if(s[i].a[1]>=s[i].a[2]&&s[i].a[1]>=s[i].a[3])
			{
				s[i].u=1;
				if(s[i].a[2]>=s[i].a[3]) s[i].v=2;
				else s[i].v=3;
			}
			if(s[i].a[2]>=s[i].a[1]&&s[i].a[2]>=s[i].a[3])
			{
				s[i].u=2;
				if(s[i].a[1]>=s[i].a[3]) s[i].v=1;
				else s[i].v=3;
			}			
			if(s[i].a[3]>=s[i].a[1]&&s[i].a[3]>=s[i].a[2])
			{
				s[i].u=3;
				if(s[i].a[1]>=s[i].a[2]) s[i].v=1;
				else s[i].v=2;
			}
			ans+=s[i].a[s[i].u];
		}
		for(int i=1;i<=n;i++)
		{
			g[s[i].u][++g_[s[i].u]]=i;
		}
		for(int j=1;j<=3;j++)
		{
			if(g_[j]>n/2) 
			{
				sort(g[j]+1,g[j]+g_[j]+1,cmp);
				for(int i=n/2+1;i<=g_[j];i++) 
				{
					ans-=s[g[j][i]].a[s[g[j][i]].u]-s[g[j][i]].a[s[g[j][i]].v];
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) g[1][i]=g[2][i]=g[3][i]=0;
	}
	return 0;
} 
