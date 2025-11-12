#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w[100001];
long long z;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w[i];
		}
		sort(w+1,w+1+n);
		for(int i=1;i<=n;i++)
		z+=w[i];
		cout<<z<<endl;
	}
	else
	cout<<0<<endl;
	return 0;
}
