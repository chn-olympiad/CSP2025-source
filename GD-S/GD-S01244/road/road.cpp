#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;bool f=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f=!(ch^45);
	for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return (f?-x:x);
}
struct pp
{
	int from,to;
	long long spend;
}a[1000005],dl[15][10005];
int n,m,k,f[10005],p,wz[10005];
long long sum,ans,c[15];
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
bool cmp(pp a,pp b)
{
	return a.spend<b.spend;
}
priority_queue<pair<long long,int>> q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		a[i].from=read();
		a[i].to=read();
		a[i].spend=read();
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].from)!=find(a[i].to))
		{
			dl[0][++p].from=a[i].from;
			dl[0][p].to=a[i].to;
			dl[0][p].spend=a[i].spend;
			f[f[a[i].from]]=f[a[i].to];
			ans+=a[i].spend;
		}
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			dl[i][j].from=n+i;
			dl[i][j].to=j;
			dl[i][j].spend=read();
		}
		sort(dl[i]+1,dl[i]+1+n,cmp);
	}
	for(int i=1;i<(1<<k);i+=2)
	{
		sum=0;
		for(int j=1;j<=k;j++)
		{
			if(((1<<(j-1))&i))
			{
				q.push({-dl[j][1].spend,j});
				sum+=c[j];
			}
		}
		q.push({-dl[0][1].spend,0});
		for(int j=0;j<=k;j++) wz[j]=1;
		for(int j=1;j<=n+k;j++) f[j]=j;
		while(1)
		{
			p=q.top().second;
			q.pop();
			if(find(dl[p][wz[p]].from)!=find(dl[p][wz[p]].to))
			{
				f[f[dl[p][wz[p]].from]]=f[dl[p][wz[p]].to];
				sum+=dl[p][wz[p]].spend;
			}
			if(sum>=ans||p&&wz[p]==n||!p&&wz[p]==n-1) break;
			wz[p]++;
			q.push({-dl[p][wz[p]].spend,p});
		}
//		cout<<sum<<"\n";
		if(ans>sum) ans=sum;
	}
	printf("%lld\n",ans);
	return 0;
}
