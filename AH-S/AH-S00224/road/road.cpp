#include<bits/stdc++.h>
#define int long long 
using namespace std;

int n,m,k;

struct jd
{
	int a,b,c;
}bian[1000050];
int cmp(jd a,jd b)
{
	return a.c<b.c;
}

int fa[100050];
int findfa(int x)
{
	while(fa[x]!=x)
	{
		x=fa[x]=findfa(fa[x]);
	}
	return x;
}

void mintree(int biannum)
{
	for(int i=1;i<=n;i++) fa[i]=i;
	int ans=0;
	sort(bian+1,bian+1+biannum,cmp);
	for(int i=1;i<=biannum;i++)
	{
		int f_a=findfa(bian[i].a);
		int f_b=findfa(bian[i].b);
		if(f_a==f_b) continue;
		ans+=bian[i].c;
		fa[f_a]=f_b;
	}
	cout<<ans;
}	

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		bian[i].a=a,bian[i].b=b,bian[i].c=c;
	}
	
	int biannum=m;
	for(int i=1;i<=k;i++)
	{
		int njd1=n+(i*2-1);
		int njd2=n+(i*2);
		int cst;
		cin>>cst;
		biannum++;
		bian[biannum].a=njd1,bian[biannum].b=njd2,bian[biannum].a=cst;
		for(int j=1;j<=n;j++)
		{
			cin>>cst;
			biannum++;
			bian[biannum].a=njd1,bian[biannum].b=i,bian[biannum].c=cst;
			biannum++;
			bian[biannum].a=njd2,bian[biannum].b=i,bian[biannum].c=cst;
		}
	}
	mintree(biannum);
	return 0;
}
