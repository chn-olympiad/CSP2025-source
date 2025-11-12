#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=2e4+5,M=2e6+5;
int n,m,k,cnt,fa[N],b[N];
long long ans,ans1;
bool pos[M];
struct ooo
{
	int st;
	int ed;
	long long val;
};
long long val;
vector<ooo>a[N],c[N];
ooo line[M];
bool cmp(ooo x,ooo y)
{
	return x.val<y.val;
}
int get_fa(int x)
{
	if(x==fa[x])
	return x;
	fa[x]=get_fa(fa[x]);
	return fa[x];
}
int main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int st,ed;
		long long val;
		scanf("%d%d%lld",&st,&ed,&val);
		cnt++;
		line[cnt]=(ooo){st,ed,val};
		a[st].push_back((ooo){st,ed,val});
		a[ed].push_back((ooo){ed,st,val});
	}
	
	for(int i=1;i<=n+2*k;i++)
	{
		fa[i]=i;
	}
	sort(line+1,line+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int x=line[i].st,y=line[i].ed,val=line[i].val;
		
		int fa_x=get_fa(x),fa_y=get_fa(y);
		if(fa_x!=fa_y)
		{
			fa[fa_x]=fa_y;
			ans1+=val;
		}
	}
	int d=0; 
	for(int i=1;i<=k;i++)
	{
		long long y;
		scanf("%lld",&y);
		d+=y;
		a[n+i].push_back((ooo){n+i,n+i+k,y});
		a[n+i+k].push_back((ooo){n+i+k,n+i,y});
		cnt++;
		line[cnt]=(ooo){n+i,n+i+k,val};
		for(int j=1;j<=n;j++)
		{
			long long x;
			scanf("%lld",&x);
			a[n+i].push_back((ooo){n+i,j,x});
			a[j].push_back((ooo){j,n+i,x});
			cnt++;
			line[cnt]=(ooo){n+i,j,x};
			
			a[n+i+k].push_back((ooo){n+i+k,j,x});
			a[j].push_back((ooo){j,n+i+k,x});
			cnt++;
			line[cnt]=(ooo){n+i+k,j,x};
			
		}
	}
	for(int i=1;i<=n+2*k;i++)
	{
		fa[i]=i;
	}
	sort(line+1,line+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int x=line[i].st,y=line[i].ed,val=line[i].val;
		
		int fa_x=get_fa(x),fa_y=get_fa(y);
		if(fa_x!=fa_y)
		{
			b[x]++;
			b[y]++;
			fa[fa_x]=fa_y;
			ans+=val;
			pos[i]=1;
		}
	}
	cout<<min(ans1,ans);
	return 0;
 } 
