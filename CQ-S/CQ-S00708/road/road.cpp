#include <bits/stdc++.h>
using namespace std;

int n,m,k;

const int M=2e5+5;
const int N=1e6+5;

struct node
{
	int start,to,d;
}edge[N],v[M];

bool cmp(node x, node y)
{
	return x.d<y.d;
}

int f[M];

int find(int x)
{
	if (f[x]==x) return x;
	return f[x]=find(f[x]);
}

void init(int t)
{
	for (int i=1; i<=t; i++)
	{
		f[i]=i;
	}
}

long long ans;
int tot;

void kruskal()
{
	init(n);
	for (int i=1; i<=m; i++)
	{
		int x=find(edge[i].start);
		int y=find(edge[i].to);
		if (x!=y)
		{
			v[++tot]=edge[i];
			ans+=edge[i].d;
			f[x]=y;
			if (tot==n-1) return;
		}
	}
}

int a[15];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1; i<=m; i++)
	{
		int l,r,d;
		scanf("%d %d %d",&l,&r,&d);
		edge[i].start=l;
		edge[i].to=r;
		edge[i].d=d;
	}
	sort(edge+1,edge+m+1,cmp);
	kruskal();
//	cout<<ans<<"\n";
	for (int i=1; i<=k; i++)
	{
		scanf("%d",&a[i]);
		for (int j=1; j<=n; j++)
		{
			scanf("%d",&v[++tot].d);
			v[tot].start=n+i;
			v[tot].to=j;
		}
	}
	sort(v+1,v+tot+1,cmp);
	for (int i=0; i<=(1<<k)-1; i++)
	{
		int tmp=i;
		int num=0;
		long long sum=0;
		while (tmp)
		{
			num++;
			if (tmp%2==1) sum+=a[num];
			tmp/=2;
		}
		if (sum>ans) continue;
		init(n+num);
		int cnt=0;
		for (int j=1; j<=tot; j++)
		{
			if (sum>ans) break;
			if (v[j].start>n and ((i>>(v[j].start-n-1))&1)==0) continue;
			int x=find(v[j].start),y=find(v[j].to);
			if (x!=y)
			{
				cnt++;
				sum+=v[j].d;
				f[x]=y;
//				cout<<v[j].start<<" "<<v[j].to<<" "<<v[j].d<<"}";
				if (cnt==n+num-1) break;
			}
		}
//		cout<<i<<" "<<sum<<"\n";
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

