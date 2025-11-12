#include<bits/stdc++.h>
using namespace std;
long long n,m,k,su,sv,sw,c[15],vr[15][10005],r[10005],rl[10005],f[10005],cnt,ans,ret; 
struct edge
{
	long long to,w;
};
vector<edge>a[10005];
void ikun(long long u,long long la)
{
	if(f[u])
	{
		long long rma=0,ok=0,hl,jl;
		for(long long i=1;i<=cnt;i++)
		{
			if(r[i]==u) ok=1;
			if(!ok||r[i]==u) continue;
			if(rl[i]>=rma) rma=rl[i],ret=r[i-1],jl=r[i];
		}
		for(long long i=0;i<a[ret].size();i++) if(a[ret][i].to==jl){a[ret][i].to=-1;break;}
		for(long long i=0;i<a[jl].size();i++) if(a[jl][i].to==ret){a[jl][i].to=-1;break;}
		ans-=rma,cnt--;
		f[u]=0;
		return;
	}
	f[u]=1;
	for(long long i=0;i<a[u].size();i++)
	{
		long long v=a[u][i].to;
		if(v==la||v==-1) continue;
		r[++cnt]=v,rl[cnt]=a[u][i].w;
		ikun(v,u);
		if(ret!=0&&u!=ret)
		{
			f[u]=0,cnt--;
			return;
		}
		else ret=0;
	}
	f[u]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0),ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(long long i=0;i<m;i++)
	{
		cin>>su>>sv>>sw;
		a[su].push_back({sv,sw});
		a[sv].push_back({su,sw});
		ans+=sw;
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long j=1;j<=n;j++) cin>>vr[i][j];
	}
	r[++cnt]=1;
	ikun(1,-1);
	cout<<ans;
	return 0;
}
//16:42 完辣！不会最小生成树，然后自己想到最小生成树的算法了qwq
//16:45 大概的话：找环，找到一个环就删掉环上权值最大的边 
//16:56 前面这种方法被后效性制裁了，可恶
//17:00 好吧其实没有，只要每次走权值最大的边即可，然后走到之前走过的边的时候就判环，然后删掉最后走的权值最大的环 
//17:02 搞迷惑行为大赏的人不要管我为什么用ikun()，习惯了 
//17:30 拿不了部分分，先放着 
//18:02 其实没放着，把16分拿了。能过（真的吗？），太好了。 
