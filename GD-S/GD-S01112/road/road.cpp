#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
long long n,m,i,j,k,dis[11000],cnt,x,y,z,sum,c[11000],ans,a[15][11000],kk;
bool b[11000];
vector<pair<long long,long long> > w[11000],ww[11000];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
void prim()
{
	dis[1]=0;
	long long i;
	for(i=0;i<w[1].size();i++)
	{
		dis[w[1][i].first]=w[1][i].second;
		q.push(make_pair(w[1][i].second,w[1][i].first));
	}
	for(i=2;i<=cnt;i++)
	{
		while(b[q.top().second]||dis[q.top().second]<q.top().first) q.pop();
		long long x=q.top().second;
		sum=sum+q.top().first;
		q.pop();
		if(sum>ans) return;
		b[x]=1;
		long long j;
		if(i==cnt) return;
		for(j=0;j<w[x].size();j++)
		{
			long long s=w[x][j].first;
			if(dis[s]>w[x][j].second)
			{
				dis[s]=w[x][j].second;
				q.push(make_pair(dis[s],s));
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&kk);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		ww[x].push_back(make_pair(y,z));
		ww[y].push_back(make_pair(x,z));
	}
	for(i=1;i<=kk;i++)
	{
		scanf("%lld",&c[i]);
		for(j=1;j<=n;j++)
		   scanf("%lld",&a[i][j]);
	}
	ans=1e15;
	for(i=0;i<(1<<kk);i++)
	{
		while(!q.empty()) q.pop();
		for(j=1;j<=n;j++) 
		{
		   w[j]=ww[j];
		   b[j]=0;
		   dis[j]=1e15;
	    }
		cnt=n;
		sum=0;
		for(j=0;j<kk;j++)
		{
			if(i&(1<<j))
			{
				sum+=c[j+1];
				cnt++;
				w[cnt].clear();
				b[cnt]=0;
				dis[cnt]=1e15;
				for(k=1;k<=n;k++)
				   {
				   	w[cnt].push_back(make_pair(k,a[j+1][k]));
				   	w[k].push_back(make_pair(cnt,a[j+1][k]));
				   }
			}
		}
		prim();
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
