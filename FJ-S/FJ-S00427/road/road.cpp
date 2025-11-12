# include <bits/stdc++.h>
# define ll long long
using namespace std;
const ll N =10010,M=1e6+10;
ll n,m,k,c[11],a[11][N];
ll head[N],nxt[M<<1],to[M<<1],go[M<<1],cnt;
void add(ll x,ll y,ll z)
{
	nxt[++cnt]=head[x];head[x]=cnt;
	to[cnt]=y;go[cnt]=z;
}
bool isi[N],sbg[11];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
	ll x,y,z;
	scanf("%lld%lld%lld",&x,&y,&z);
	add(x,y,z);add(y,x,z);
	}
	for(int i=1;i<=k;i++)
	{
	scanf("%lld",&c[i]);
	for(int j=1;j<=n;j++)
	scanf("%lld",&a[i][j]);
	}
	ll x=1,num=0,sum=0;isi[x]=1;
	while(num<n-1)
	{
		ll Min=1e10,id=-1,idj=-1;
		for(int i=1;i<=n;i++)
		if(!isi[i])
		for(int j=1;j<=k;j++)
		if(Min>(!(sbg[j]))*c[j]+a[j][x]+a[j][i])
		Min=(!(sbg[j]))*c[j]+a[j][x]+a[j][i],id=i,idj=j;
		
		ll Min2=1e10,idt=-1;
		for(int i=head[x];i;i=nxt[i])
		if(!isi[to[i]] && go[i]<Min2)idt=to[i],Min2=go[i];
		
		if(idt==-1) num++,x=id,sum+=Min,isi[x]=1,sbg[idj]=1;
		else if(id==-1) num++,x=idt,sum+=Min2,isi[x]=1;
		else{
			if(Min2<Min)x=idt,sum+=Min2,isi[x]=1;
			else sum+=Min,x=id,isi[x]=1,sbg[idj]=1;
			++num;
		}
	}
	cout<<sum;
}
