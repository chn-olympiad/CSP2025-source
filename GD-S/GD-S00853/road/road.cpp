#include <bits/stdc++.h>
using namespace std;

int cfei[11];
pair<int,int> lnodes[1100010];
//pair<int,int> cnodes[11][1010];
int lk[1100010];
int cunk[11][1010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;

struct bingn{
	int fa;
} bn[10020];

int getfa(int n)
{
	if(bn[n].fa!=n) 
	{
		bn[n].fa = getfa(bn[n].fa);
		return bn[n].fa;
	}
	else return n;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int t1,t2,t3;
	for(int i=1;i<=m;i++)
	{
		cin>>t1>>t2>>t3;
		lnodes[i].first=t1;
		lnodes[i].second=t2;
		lk[i]=t3;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>cfei[i];
		for(int j=1;j<=n;j++)
		{
			cin>>cunk[i][j];
		}
	}
	int minans=0x7fffffff;
	int maxvis=1,kt=k;
	for(int i=1;i<=kt;i++) maxvis*=2;
	for(int i=0;i<maxvis;i++)
	{
		for(int i=1;i<=m;i++) 
		{
			pq.push(make_pair(lk[i],i));
		}
		int vis=i;
		int cunp=1;
		int nodes=m;
		int ans=0;
		while(vis>0)
		{
			if(vis&1)
			{
				ans+=cfei[cunp];
				for(int i=1;i<=n;i++)
				{
					pq.push(make_pair(cunk[cunp][i],m+i+10000*cunp));
					lnodes[m+i+10000*cunp]=make_pair(i,n+cunp);
				}
				nodes++;
			}
			cunp++;
			vis/=2;
		}
		
		for(int i=1;i<=nodes;i++)
		{
			bn[i].fa=i;
		}
				
		while(!pq.empty())
		{
			int np=pq.top().second;
			int n1=lnodes[np].first;
			int n2=lnodes[np].second;

			int fan1=getfa(n1),fan2=getfa(n2);
			if(fan1!=fan2)
			{
				bn[fan2].fa=fan1;
				ans+=pq.top().first;
				//cout<<n1<<' '<<n2<<endl;
			}
			pq.pop();
		}
		if(minans>ans) minans=ans;
	//	cout<<ans<<endl;
	}
	cout<<minans;
}
