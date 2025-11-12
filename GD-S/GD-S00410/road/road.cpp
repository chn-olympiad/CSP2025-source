#include<bits/stdc++.h>
using namespace std;
int n,m,k,len;
long long c[15],sum,ans=0x3f3f3f3f3f3f3f3f;
long long tj[15],tjlen[15];
int p[10210];
struct node{
	int u,v,id;
	long long w;
}edge[2000010];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
void ksl(int ctw)
{
	sum=0;
//	for(int i=1;i<=k;i++)
//	{
//		tjlen[i]=0;
//		tj[i]=0;
//	}
	for(int i=1;i<=n+k;i++) p[i]=i;
	for(int i=1;i<=len;i++)
	{
		int u=edge[i].u,v=edge[i].v,id=edge[i].id;
		long long w=edge[i].w;	
		if(id!=0)
		{
			if((ctw&(1<<(id-1)))==0)
			{
				continue;
			}
		}
		if(find(u)!=find(v))
		{
//			if(edge[i].u>n)
//			{
//				tj[edge[i].u-n]+=w;
//				tjlen[edge[i].u-n]++;
//			}
//			if(edge[i].v>n)
//			{
//				tj[edge[i].v-n]+=w;
//				tjlen[edge[i].v-n]++;
//			}
			p[find(u)]=find(v);
			sum+=w;
		}
	}
//	cout<<sum<<'\n';
//	for(int i=1;i<=k;i++)
//	{
//		cout<<tjlen[i]<<" "<<tj[i]<<'\n';
//		if(tjlen[i]>=2) sum+=c[i];
//		else sum-=tj[i];
//	}
	int wei=0;
	while(ctw)
	{
		if(ctw&1)
		{
			sum+=c[wei+1];
		}
		ctw>>=1;
		wei++;
	}
	ans=min(ans,sum);
}
void ksl2()
{
	sum=0;
	for(int i=1;i<=k;i++)
	{
		tjlen[i]=0;
		tj[i]=0;
	}
	for(int i=1;i<=n+k;i++) p[i]=i;
	for(int i=1;i<=len;i++)
	{
		int u=edge[i].u,v=edge[i].v,id=edge[i].id;
		long long w=edge[i].w;	
//		if(id!=0)
//		{
//			if((ctw&(1<<(id-1)))==0)
//			{
//				continue;
//			}
//		}
		if(find(u)!=find(v))
		{
			if(edge[i].u>n)
			{
				tj[edge[i].u-n]+=w;
				tjlen[edge[i].u-n]++;
//				cout<<1;
			}
			if(edge[i].v>n)
			{
				tj[edge[i].v-n]+=w;
				tjlen[edge[i].v-n]++;
//				cout<<1;
			}
			p[find(u)]=find(v);
			sum+=w;
		}
	}
//	cout<<sum<<'\n';
	for(int i=1;i<=k;i++)
	{
		if(tjlen[i]<2) sum-=tj[i];
	}
//	int wei=0;
//	while(ctw)
//	{
//		if(ctw&1)
//		{
//			sum+=c[wei+1];
//		}
//		ctw>>=1;
//		wei++;
//	}
	ans=min(ans,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		++len;		
		edge[len].id=0;
		cin>>edge[len].u>>edge[len].v>>edge[len].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			++len;
			edge[len].u=n+i,edge[len].v=j,edge[len].id=i;
			cin>>edge[len].w;
		}
	}
	sort(edge+1,edge+1+len,cmp);
	if(k<=5)
	{
		for(int i=0;i<=((1<<k)-1);i++)
		{
			ksl(i);
		}
	}
	else
	{
		ksl2();
	}
	cout<<ans;
	return 0;
}
