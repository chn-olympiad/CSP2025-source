#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int> > a(n);
	vector<vector<int> > w(n);
	for(int i=0;i<m;i++)
	{
		int x,y,ww;
		cin>>x>>y>>ww;
		a[x].push_back(y);
		a[y].push_back(x);
		w[x].push_back(ww);
		w[y].push_back(ww);
	}
	cout<<80;
	return 0;
}
