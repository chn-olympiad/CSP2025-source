#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N=1e4+50;
const int M=2e6+10;

int n,m,k;
struct h{
	int u,v;
	int w;
}e[M];
int c[11];
h l[11][N];
h p[2][M];
int cnt,cnta,cntb;
int ans=-1;

bool cmp(h a,h b){return a.w<b.w;}

int merge(h p[],h a[],h b[],int lena,int lenb)
{
	int len=0,pa=1,pb=1;
	while(pa<=lena&&pb<=lenb)
	{
		if(a[pa].w<b[pb].w) p[++len]=a[pa++];
		else p[++len]=b[pb++];
	}
	while(pa<=lena) p[++len]=a[pa++];
	while(pb<=lenb) p[++len]=b[pb++];
	return lena+lenb;
}

int f[N];
int _find(int x)
{
	if(f[f[x]]!=f[x]) f[x]=_find(f[x]);
	return f[x];
}
int count(h p[],int len,int num)
{
	int sum=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	int i=1,j=1,u,v;
	p[len+1].w=e[m+1].w=1000000000000;
	while(num>1)
	{
		if(p[i].w>e[j].w)
		{
			u=_find(e[j].u),v=_find(e[j].v);
			if(u-v)
			{
				sum+=e[j].w;
				num--;
				f[u]=v;
			}
			j++;
		}
		else
		{
			u=_find(p[i].u),v=_find(p[i].v);
			if(u-v)
			{
				sum+=p[i].w;
				num--;
				f[u]=v;
			}
			i++;
		}
	}
	return sum;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>l[i][j].w,l[i][j].u=i+n,l[i][j].v=j;
		sort(l[i]+1,l[i]+1+n,cmp);
	}
	
	int lenp[2],id,num,delta;
	for(int j=0;j<(1<<k);j++)
	{
		bool flag=0;
		lenp[1]=lenp[0]=id=delta=0,num=n;
		for(int i=1;i<=k;i++)
		if(j>>i-1&1)
		{
			num++,delta+=c[i];
			if(flag) lenp[id^1]=merge(p[id^1],p[id],l[i],lenp[id],n),id^=1;
			else
			{
				for(int t=1;t<=n;t++) p[id][t]=l[i][t];
				lenp[id]=n;
				flag=1;
			}
		}
		
		int now=count(p[id],lenp[id],num)+delta;
		if(ans==-1||ans>now) ans=now;
	}
	cout<<ans;
	return 0;
}
