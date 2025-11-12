#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<ctime>
#include<cstdlib>
#define int long long
const int N=2119850;
const int M=1000000007;
using namespace std;
char cvb;
int re()
{
	int dfg=0,fgh=1;
	cvb=getchar();
	while(cvb>'9'||cvb<'0')
	{
		if(cvb=='-') fgh=-1;
	cvb=getchar();
		}
	while(cvb>='0'&&cvb<='9')
	{
		dfg=(dfg<<1)+(dfg<<3)+cvb-'0';
	cvb=getchar();
		}
	return dfg*fgh;
}
	double t1,t2;
int tot,n,m,k,a[15][N],head[N<<1],x,y,z,vi[N<<1],d[N<<1],pd,PD,ans,sum;
struct ed
{
	int to,nxt,val;
	}e[N<<2];
void add(int xx1,int xx2,int v)
{
	//cout<<xx1<<' '<<xx2<<' '<<v<<endl;
	e[++tot].nxt=head[xx1];
	head[xx1]=tot;
	e[tot].to=xx2;
	e[tot].val=v;
}
priority_queue<pair<int,int> >q;
pair<int,int>now;
void dfs()
{
	sum=0;
	//tot=0;
	q.push(make_pair((int)0,(int)1));
	while(!q.empty())
	{
		
		x=-q.top().first;
		y=q.top().second;
		d[y]=x;
		tot++;
		//cout<<y<<' '<<x<<endl;
		q.pop();
		if(vi[y]==1) continue;
		vi[y]=1;
		sum+=x;
		for(int i=head[y];i;i=e[i].nxt){
//	tot++;
		  if(!vi[e[i].to]&&e[i].val<d[e[i].to])
		  {
	//		  	tot++;
	//t1=1.0*clock()/CLOCKS_PER_SEC;
			  d[e[i].to]=e[i].val;
			  now.first=-e[i].val;
			  now.second=e[i].to;
	//t2=1.0*clock()/CLOCKS_PER_SEC;
	//cout<<t2-t1<<endl;
			  q.push(now);
	//t2=1.0*clock()/CLOCKS_PER_SEC;
	//cout<<t2-t1<<endl<<endl;
			  }}
	}
	//cout<<tot<<endl;
}
void workA()
{
	for(int i=n+1;i<=n+k;i++) vi[i]=1;
	for(int j=1;j<=n;j++) {vi[j]=0; d[j]=M*n;}
	for(int i=1;i<=k;i++)
	for(int j=1;j<=n;j++)
	  if(a[i][j]==0)
	  {
		  for(int l=1;l<=n;l++)
		    if(l!=j)
		      {add(l,j,a[i][l]); add(j,l,a[i][l]);}
		  break;
		  }
    dfs();
    ans=sum;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	t1=1.0*clock()/CLOCKS_PER_SEC;
	n=re();
	m=re();
	k=re();
	ans=M*n;
	for(int i=1;i<=m;i++)
	{
		x=re();
		y=re();
		z=re();
		add(x,y,z);
		add(y,x,z);
		}
    for(int i=1;i<=k;i++)
    {
		z=re();
		if(z==0) PD++;
		pd=0;
		add(i+n,i+n+k,z);
		for(int j=1;j<=n;j++)
		{
			a[i][j]=z=re();
			if(z==0) pd++;
			add(j,i+n,z);
			add(i+n+k,j,z);
			}
		if(pd>0) PD++;
		}
    if(PD>=k*2) workA();
    else for(int i=0;i<(1<<k);i++)
    {
		x=i;
		for(int j=1;j<=k;j++)
		{
			vi[n+j+k]=vi[n+j]=x%2;
			d[n+j+k]=d[n+j]=M*n;
			//cout<<x%2<<' ';
			x/=2;
			}
		for(int j=1;j<=n;j++) {vi[j]=0; d[j]=M*n;}
		dfs();
		//cout<<i<<' '<<sum<<endl;
		ans=min(ans,sum);
	}
	t2=1.0*clock()/CLOCKS_PER_SEC;
	cout<<ans;
	//cout<<endl<<t2-t1;
	return 0;
}
