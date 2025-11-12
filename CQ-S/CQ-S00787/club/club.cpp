#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int f,s,t;
	int gx;
}a[100001];
bool cmp(node p,node q)
{
	return p.gx<q.gx;
}
int n;
int ans=0;
void dfs(int x,int cf,int cs,int ct,int sum)
{
	if (x>n)
	{
		ans=max(ans,sum);
		return;
	}
	if (cf<n/2)dfs(x+1,cf+1,cs,ct,sum+a[x].f);
	if (cs<n/2)dfs(x+1,cf,cs+1,ct,sum+a[x].s);
	if (ct<n/2)dfs(x+1,cf,cs,ct+1,sum+a[x].t);
}
int main ()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].f>>a[i].s>>a[i].t;
			a[i].gx=a[i].f-a[i].s;
		}
		if (n<=10)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		for (int i=1;i<=n;i++)ans+=a[i].f;
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=n/2;i++)
		{
			ans-=a[i].gx;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

