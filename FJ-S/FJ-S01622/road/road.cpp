#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long>PII;
long long tot=0,head[2500005],ver[2500005],nx[2500005],vw[2500005];
long long cw[11][10001],cwj[11],head1[10][10001];
void add(long long x,long long y,long long w){
	tot++;
	nx[tot]=y;
	vw[tot]=w;
	ver[tot]=head[x];
	head[x]=tot;
}
bool vis[2100001];
int n,m,k;
long long ans=0;
long long zxscs()
{
	priority_queue<PII , vector<PII> , greater<PII > > q;
	long long sum=0;
	vis[1]=1;
	for(int i=head[1];i!=-1;i=ver[i])
		q.push({vw[i],nx[i]});
	while(!q.empty())
	{
		long long w=q.top().first,y=q.top().second;
		q.pop();
		if(!vis[y])
		{
			sum+=w;
			vis[y]=1;
			for(int i=head[y];i!=-1;i=ver[i])
			{
				q.push({vw[i],nx[i]});
			}
		}
	}
	return sum;
}
//bool visk[100];
void dfs(int si,int sum,int now)
{
	if(si==0)
	{
		for(int i=1;i<=n+k;i++)
		vis[i]=0;
		long long w=zxscs();
		ans=min(ans,sum+w);
		return ;
	}
	if(sum==0)
	{
		for(int j=1;j<=n+10;j++)
		head1[si][j]=head[j];
		for(int j=1;j<=n;j++)
		{
			add(now-1+n,j,cw[now-1][j]);
			add(j,now-1+n,cw[now-1][j]);
		}
		dfs(si-1,sum+cwj[now-1],now-1);
		for(int j=1;j<=n+10;j++)
		head[j]=head1[si][j];
		tot-=2*n;
	}
	else
	{
		for(int i=now-1;i>=si;i--)
		{
			for(int j=1;j<=n+10;j++)
			head1[si][j]=head[j];
			for(int j=1;j<=n;j++)
			{
				add(i+n,j,cw[i][j]);
				add(j,i+n,cw[i][j]);
			}
			dfs(si-1,sum+cwj[i],i);
			for(int j=1;j<=n+10;j++)
			head[j]=head1[si][j];
			tot-=2*n;
		}
	}
	
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head , -1 , sizeof(head));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		long long a,b,w;
		scanf("%lld %lld %lld",&a,&b,&w);
		add(a,b,w);
		add(b,a,w);
	}
	ans=zxscs();
	if(k==0)
	{
		cout<<ans;
		return 0;
	}//cout<<ans;
	for(int i=1;i<=k;i++)
	{
		cin>>cwj[i];
		for(int j=1;j<=n;j++)
		cin>>cw[i][j];
		
		if(cwj[i]>=ans)
		i--,k--;
		else 
		for(int j=1;j<=i;j++){
			dfs(j,0,i+1);
		}
	}
	cout<<ans;
	return 0;
}
