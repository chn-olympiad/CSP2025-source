#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10010;
vector<pair<int,int> > G[N]; //pair<Node,Weight>
int n,m,k;
int c[15][N];
bool vis[N];
struct Edge
{
	int from,to,w;
};
bool judge()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=vis[i];
	}
	if(cnt<n)
	{
		return false;
	}
	return true;
}
int FFF()
{
	int sum=0;
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq;
//	cout<<"----------\n";
	for(pair<int,int> too:G[1])
	{
		int to=too.first,from=1,w=too.second;
		pq.push(make_pair(w,make_pair(from,to)));
//		cout<<from<<' '<<to<<' '<<w<<endl;
	}
//	cout<<"----------\n";
	vis[1]=true;
	int selectedcnt=1;
	while(!judge())
	{
		pair<int,pair<int,int> > tmp=pq.top();
		pq.pop();
		int to=tmp.second.second,from=tmp.second.first;
//		cout<<from<<' '<<to<<' '<<tmp.first<<endl;
		if(!vis[to])
		{
			vis[to]=true;
			selectedcnt++;
			sum+=tmp.first;
//			cout<<"to="<<to<<endl;
			for(pair<int,int> too:G[to])
			{
				int tooo=too.first,fromm=to,w=too.second;
//				cout<<"----"<<fromm<<' '<<tooo<<' '<<w<<endl;
				if(!vis[tooo])
				{
					pq.push(make_pair(w,make_pair(fromm,tooo)));
//					cout<<"passed\n";
				}
			}
		}
	}
	return sum;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>c[i][j];
			if(j>0)
			{
				G[n+i].push_back(make_pair(j,c[i][j]));
				G[j].push_back(make_pair(n+i,c[i][j]));
			}
		}
	}
	printf("%lld\n",FFF());
	fclose(stdin);
	fclose(stdout);
	return 0;
}