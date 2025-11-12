#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,num;
int ans=2e18;
int a[31];
int fa[200001];
struct nt
{
	int x,y,z;
}E[2000001],t[2000001];
pair<int,int>ex[31][20001];
int id[31],it[31];
bool cmp(nt x,nt y)
{
	return x.z<y.z;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
nt ck()
{
	nt mi={0,0,(int)2e9};
	int idx=-1;
	if(it[0]<=m) mi={E[it[0]].x,E[it[0]].y,E[it[0]].z},idx=0;
	for(int i=1;i<=num;++i)
	{
		if(it[i]>n) continue;
		int x=id[i]+n,y=ex[id[i]][it[i]].second,z=ex[id[i]][it[i]].first;
		if(z<mi.z) mi={x,y,z},idx=i;
	}
	if(mi.z==2e9) return {-1,-1,-1};
	it[idx]++;
	return mi;
}
void get()
{
	for(int i=1;i<=n+k;++i) fa[i]=i;
	int cnt=0,res=0;
	for(int i=0;i<=num;++i) it[i]=1,cnt+=a[id[i]];
	nt x=ck();
	while(x.z!=-1)
	{
		int A=find(x.x),B=find(x.y);
		if(A!=B)
		{
			fa[A]=B,cnt+=x.z;
			res++;
		}
		if(cnt>=ans) return;
		if(res==n+num-1) break;
		x=ck();
	}
	ans=cnt;
	return;
} 
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		t[i]={x,y,z};
	}
	stable_sort(t+1,t+1+m,cmp);
	int cnt=0;
	for(int i=1;i<=m;++i)
	{
		int x=t[i].x,y=t[i].y,z=t[i].z;
		x=find(x),y=find(y);
		if(x!=y) fa[x]=y,E[++cnt]={x,y,z};
		if(cnt==n-1) break;
	}
	m=cnt;
	for(int i=1;i<=k;++i)
	{
		cin>>a[i];
		for(int j=1;j<=n;++j) cin>>ex[i][j].first,ex[i][j].second=j;
		stable_sort(ex[i]+1,ex[i]+1+n);
	}
	for(int mk=0;mk<(1<<k);mk++)
	{
		num=0;
		for(int j=1;j<=k;j++)
		{
			if(mk&(1<<(j-1))) id[++num]=j;
		}
		get();
	}
	cout<<ans<<"\n";
	return 0;
}
//I wonder how, I wonder why.
//Yesterday you tell me about the bule bule sky.
