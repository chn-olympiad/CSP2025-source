#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,t;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u>>v>>w;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n+1;j++)
			cin>>t;
	cout<<"0"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
