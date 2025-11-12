#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,a[N][3],cnt[3],s[N];
struct node
{
	int i,j;
	bool operator<(const node x)const
	{
		if(!j)
			return a[i][0]+max(a[i][1],a[i][2])>a[x.i][x.j]+max(a[x.i][1],a[x.i][2]);
		if(j==1)
			return a[i][1]+max(a[i][0],a[i][2])>a[x.i][x.j]+max(a[x.i][0],a[x.i][2]);
		return a[i][2]+max(a[i][0],a[i][1])>a[x.i][x.j]+max(a[x.i][0],a[x.i][1]);
	}
};
priority_queue<node> q[3];
bool cmp(node x,node y)
{
	return a[x.i][x.j]>a[y.i][y.j];
}
void dfs(int x)
{
	if(x==n+1)
	{
		int tot=0;
		for(int i=1;i<=n;++i)
			tot+=a[i][s[i]];
		ans=max(ans,tot);
		return;
	}
	for(int i=0;i<3;++i)
		if(cnt[i]<n/2)
		{
			cnt[i]++;
			s[x]=i;
			dfs(x+1);
			cnt[i]--;
		}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=0;j<3;++j)
			cin>>a[i][j];
	if(n<=10)
	{
		cnt[0]=cnt[1]=cnt[2]=ans=0;
		dfs(1);
		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;++i)//能过样例1,2,玄学 
	{
		node t[3]={{i,0},{i,1},{i,2}};
		while(1)
		{
			sort(t,t+3,cmp);
			bool ok=0;
			for(int j=0;j<3;++j)
			{
				if(q[j].size()<n/2)
				{
					q[j].push(t[j]);
					ok=1;
					break;
				}
				else if(t[j]<q[j].top())
				{
					int iti=t[j].i,itj=t[j].j;
					for(int k=0;k<3;++k)
						t[k].i=q[j].top().i,t[k].j=q[j].top().j;
					q[j].pop();
					q[j].push(node{iti,itj});
					break;
				}
			}
			if(ok)
				break;
		}
	}
	ans=0;
	for(int i=0;i<3;++i)
		while(!q[i].empty())
		{
			ans+=a[q[i].top().i][q[i].top().j];
			q[i].pop();
		}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}
