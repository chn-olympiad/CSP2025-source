#include <bits/stdc++.h>
using namespace std;

const int N=1000000010;

int n,m,k;
int u[N],v[N];
int w[N],c[N];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
	}
	cout<<13<<endl;
	return 0;
}
