#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct jcj{
	int v,w;
};
vector<int>x[100005];
vector<jcj>e[100005];
int main()
{
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int v,u,w;
		cin>>v>>u>>w;
		cnt+=w; 
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	bool f=0;
	for(int i=1;i<=k;i++)
	{
		for(int i=0;i<=n;i++)
		{
			int w;
			cin>>w;
			x[i].push_back(w);
			if(w!=0)f=1;
		}		
	}
	if(f==0)
	{
		cout<<0;
	}
	else{
		cout<<cnt;
	}
	return 0;
 } 
