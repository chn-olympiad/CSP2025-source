#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
long long sum=0,jian=0,jian2[700];
int cnt,vis[700][10001];
int cnt2,n,m,j,l[11];
bool e[700][11];
struct node
{
	int u,v,s;
	long long q;
}a[1000001];
bool cmp(node x,node y)
{
	if(x.q>y.q)
	return 0;
	return 1;
}
void chuj(int step,int duo)
{
	cnt2++;
	if(duo!=1)
	{
	for(int i=1;i<=step;i++)
	e[cnt2][i]=e[cnt2-1][i];
	jian2[cnt2]=jian2[cnt2-1]+l[step];
	e[cnt2][step]=1;
	}
	else
	e[cnt2][step]=1,jian2[cnt2]=l[step];
	for(int i=step+1;i<=j;i++)
	chuj(i,duo+1);
}
int zu(int o,int p,int pai)
{
	if(vis[pai][o]==0)
	vis[pai][o]=o;
	if(vis[pai][p]==0)
	vis[pai][p]=p;
	if(vis[pai][o]==vis[pai][p])
	return 0;
	
	if(vis[pai][o]==o&&vis[pai][p]==p)
	{
		vis[pai][o]=p;
		return p;
	}
	if(vis[pai][o]==o)
	{
		int h=zu(vis[pai][o],vis[pai][p],pai);
		if(h!=0)
		vis[pai][o]=h;
		return h;
	}
	if(vis[pai][p]==p)
	{
		int h=zu(vis[pai][o],vis[pai][p],pai);
		if(h!=0)
		vis[pai][p]=h;
		return h;
	}
	vis[pai][o]=zu(vis[pai][o],vis[pai][p],pai);
	vis[pai][p]=vis[pai][o];
	return vis[pai][o];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>j;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].q;
		a[i].s=0;
	}
	cnt=m;
	int c,b[10001];
	for(long long i=1;i<=j;i++)
	{
		long long minn=1e9+1,id=0;
		cin>>c;
		for(int k=1;k<=n;k++)
		{
			cin>>b[k];
			if(minn>b[k])
			{
				minn=b[k];
				id=k;
			}
		}
		l[i]=minn+c;
		jian+=l[i];
		for(int k=1;k<=n;k++)
		{
			if(k==id)
			continue;
			cnt++,a[cnt].u=id,a[cnt].v=k,a[cnt].q=b[k],a[cnt].s=i;	
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int step=0;
	for(long long i=1;i<=n-1;)
	{
		step++;
		if(!zu(a[step].u,a[step].v,0))
		continue;
		i++;
		sum+=a[step].q;
//		cout<<a[step].u<<"&"<<a[step].v<<" "<<a[step].q<<endl;
	}
	sum+=jian;
	for(int i=1;i<=j;i++)
	chuj(i,1);
	for(long long k=1;k<=cnt2;k++)
	{
		int sum2=0;
		step=0;
		for(long long i=1;i<=n-1;)
	{
		step++;
		if(e[k][a[step].s])
		continue;
		if(!zu(a[step].u,a[step].v,k))
		continue;
		i++;
		sum2+=a[step].q;
//		for(int i=1;i<=j;i++)
//		cout<<e[k][i]<<" ";
//		cout<<"!"<<endl<<a[step].u<<" "<<a[step].v<<" "<<a[step].q<<endl; 
	}
	if((sum2+jian-jian2[k])<sum)
	{
		sum=sum2+jian-jian2[k];
		}
//		cout<<sum2+jian-jian2[k]<<" "<<sum<<endl;
	}
	cout<<sum;
	return 0;
}
