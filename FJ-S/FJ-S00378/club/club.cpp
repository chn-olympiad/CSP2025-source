#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
struct node
{
	int u,val;
}b[100010];
struct node1
{
	node v[4];
}a[100010];
bool cmp(node a,node b)
{
	return a.val>b.val;
}
bool cmp1(node a,node b)
{
	return a.val<b.val;
}
int cnt[4];
void solve()
{
	cnt[1]=cnt[2]=cnt[3]=0;
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i].v[j].val;
			a[i].v[j].u=j;	
		}
		sort(a[i].v+1,a[i].v+4,cmp);
		b[i].val=a[i].v[2].val-a[i].v[1].val;
		b[i].u=a[i].v[1].u;
		ans+=a[i].v[1].val;
	}
	sort(b+1,b+1+n,cmp1);
	for(int i=1;i<=n;i++)
	{
		if(cnt[b[i].u]<n/2)cnt[b[i].u]++;
		else ans+=b[i].val;
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)solve();
	return 0;
}
