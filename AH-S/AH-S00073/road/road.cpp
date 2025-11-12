#include <bits/stdc++.h>
using namespace std;
struct node{
	bool f;//0为直接；1为间接
	long long w;
	int kk;
};
int n,m,k;
long long Map[10001][10001];
long long C[11],MapC[11][10001];
bool vis[10001];
bool visk[11];
vector <node> S[10011];
int cnt[10011];
long long ans;
void up (int i,int x)
{
	if (x==1) return;
	if (S[i][x].w<S[i][x/2].w)
	{
		swap(S[i][x],S[i][x/2]);
		up(i,x/2);
	}
}
void down (int i,int x)
{
	if (x>=cnt[i]) return;
	if (S[i][x].w>S[i][2*x].w && 2*x<=cnt[i]-1)
	{
		swap(S[i][x],S[i][2*x]);
		down(i,x*2);
	}
	if (S[i][x].w>S[i][2*x+1].w &&  2*x+1<=cnt[i]-1)
	{
		swap(S[i][x],S[i][2*x+1]);
		down(i,x*2+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++) 
	{
		int u,v,w;
		cin>>u>>v>>w;
		Map[u][v]=Map[v][u]=w;
		if (u==1 || v==1)
		{
			cnt[1]++;
			node sss;
			sss.w=w,sss.f=0;
			S[1].push_back(sss);
			up(1,cnt[1]-1);
		}
	}
	for (int i=1;i<=k;i++)
	{
		cin>>C[i];
		for (int j=1;j<=n;j++) cin>>MapC[i][j];
		for (int j=1;j<=n;j++)
		{
			if (j!=1)
			{
				cnt[1]++;
				node sss;
				sss.w=MapC[i][j]+C[i]+MapC[i][1],sss.f=1,sss.kk=i;
				S[1].push_back(sss);
				up(1,cnt[1]-1);
			}
		}
	}
	int u=1,sum=1;
	while (sum<n)
	{
		vis[u]=1;
		for (int i=1;i<=n;i++)
		{
			if (vis[i]) continue;
			cnt[i]++;
			node sss;
			sss.w=Map[u][i],sss.f=0;
			S[i].push_back(sss);
			up(i,cnt[i]-1);
		}
		for (int kk=1;kk<=k;kk++)
		for (int i=1;i<=n;i++)
		{
			if (vis[i]) continue;
			cnt[i]++;
			node sss;
			sss.w=MapC[kk][i]+MapC[kk][u]+(visk[kk]?0:C[kk]),sss.f=1,sss.kk=kk;
			S[i].push_back(sss);
			up(i,cnt[i]-1);
		}
		node minn;
		int minw=INT_MAX;
		for (int i=1;i<=n;i++)
		{
			if (vis[i]) continue;
			node num=S[i][1];
			if (num.w<minw)
			{
				minw=num.w;
				minn=num;
				u=i;
			}
		}
		cnt[u]--;
		swap(S[u][1],S[u][cnt[u]]);
		down(u,1);
		//cout<<minn.w<<' '<<u<<'\n';
		ans+=minn.w;
		if (minn.f==1 && !visk[minn.kk])
		{
			int kkk=minn.kk;
			visk[kkk]=1;
			for (int i=1;i<=n;i++)
			{
				if (!vis[i] && i!=u) continue;
				for (int j=1;j<=n;j++)
				{
					if (vis[j] || j==u) continue;
					cnt[j]++;
					node sss;
					sss.w=MapC[kkk][i]+MapC[kkk][j],sss.f=1,sss.kk=kkk;
					S[j].push_back(sss);
					up(j,cnt[j]-1);
				}
			}
		}
		sum++;
	}
	cout<<ans;
	return 0;
}
