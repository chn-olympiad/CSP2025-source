#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[15],cnt,ans,z[15];
int f[10025],siz[10025];
struct node1{
	long long id,val;
}a[15][10005];
struct node{
	long long u,v,w;
}s[1000005],edge[200005];
int fid(int a){return f[a]==a?a:f[a]=fid(f[a]);}
priority_queue<pair<int,int>>q;
void read(long long &x)
{
	x=0;
	char ch=0;
	while('0'>ch||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		read(s[i].u);read(s[i].v);read(s[i].w);
	}
	sort(s+1,s+1+m,[](node x,node y){return x.w<y.w;}); 
	for(int i=1;i<=m;i++)
	{
		int u=fid(s[i].u),v=fid(s[i].v);
		if(u==v) continue;
		f[u]=v;edge[++cnt]=s[i];ans+=s[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		read(c[i]);
		for(int j=1;j<=n;j++) read(a[i][j].val),a[i][j].id=j;
		sort(a[i]+1,a[i]+1+n,[](node1 x,node1 y){return x.val<y.val;});
	}
	
	for(int g=1;g<(1ll<<k);g++)
	{
		while(!q.empty())q.pop();
		q.push({-edge[1].w,k+1});
		long long sum=0,ss=0;
		for(int i=1;i<=n+k;i++)f[i]=i,siz[i]=1;
		for(int i=1;i<=k+1;i++)z[i]=1;
		for(int i=1;i<=k;i++)
		{
			if((g>>(i-1))&1)
			{
				sum+=c[i];ss++;
				q.push({-a[i][1].val,i});
			}
		}
		int r=0;
		while(!q.empty())
		{
			pair<int,int>o=q.top();
			q.pop();
			int u,v;
			if(o.second>k)
			{
				u=fid(edge[z[k+1]].u);
				v=fid(edge[z[k+1]].v);
				z[k+1]++;
				if(z[k+1]<=cnt) q.push({-edge[z[k+1]].w,k+1});
			}
			else
			{
				u=fid(a[o.second][z[o.second]].id);
				v=fid(o.second+n);
				
				z[o.second]++;
				if(z[o.second]<=n) q.push({-a[o.second][z[o.second]].val,o.second});
			}
			if(u==v) continue;
			if(siz[u]>siz[v]) swap(u,v);
			siz[v]+=siz[u];r++;
			f[u]=v;sum-=o.first;
			if(sum>=ans)break;
			if(r>=n+ss-1)break;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
