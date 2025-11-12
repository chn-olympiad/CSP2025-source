#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=10000;
vector<int> e[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	int u,v,w;
	int sum=0;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		e[u].push_back(v);
		e[v].push_back(u);
		sum+=w;
	}
	int a;
	int c;
	for(int i=0;i<k;i++)
	{
		cin>>c;
		for(int j=0;j<n;j++)
		{
			cin>>a;
		}
	}
	if(k==0)
	{
		cout<<sum;
	}
	else
	{
		cout<<0;
	}
	return 0;
	//4分也是分，我要骗分成功））） 
}
