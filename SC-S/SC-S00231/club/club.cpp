#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100000;
const int CJY=-114514;
ll t,n,cnt,ans;
ll s[5],v[maxn+10];
struct node
{
	ll f[5];
}a[maxn+10];
struct Node
{
	ll num,k;
}h[2*maxn+10];
void dfs(ll now1,ll now2,ll sum,ll tot)
{
	if(tot==n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(s[i]<(n/2))
		{
			s[i]++;
			dfs(now1+1,i+1,sum+a[now1].f[i],tot+1);
			s[i]--;
		}
	}
}
bool cnm(node x,node y)
{
	return x.f[1]>y.f[1];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[i].f[1]=x,a[i].f[2]=y,a[i].f[3]=z;
		}
		int flag1=0,flag2=0;
		for(int i=1;i<=n;i++) 
		{
			if(a[i].f[2]) 
			{
				flag1=1;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].f[3])
			{
				flag2=1;
				break;
			}
		}
		if(!flag1&&!flag2)//特殊性质A
		{
			sort(a+1,a+1+n,cnm);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].f[1];
			}
			cout<<ans<<'\n';
			continue;
		}
		else
		{
			ans=CJY;
			dfs(1,1,0,0);
			cout<<ans<<'\n';
		}
		
	}
	return 0;
}