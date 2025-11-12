#include<bits/stdc++.h>
using namespace std;

int n,m,ans,s[510],w[510];
int p[510];
int vis[510];

void dfs(int step,int sumx)
{
	if(sumx+(n-step+1)<m) return;
	if(sumx>=m)
	{
		ans+=p[n-step+1];
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=step;
		int tmp=sumx;
		if(step-1-sumx<w[i] && s[step]) tmp++;
		dfs(step+1,tmp);
		vis[i]=0;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++) cin>>w[i];
	if(n<=18)
	{
		p[0]=1;
		for(int i=1;i<=n;i++) p[i]=p[i-1]*i;
		dfs(1,0);
		cout<<ans<<endl;
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(!p[i]) cnt++;
	if(cnt+m>n) cout<<0<<endl;
	return 0;
}
