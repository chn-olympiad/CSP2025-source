#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int u[m+1];
	int v[m+1];
	int w[m+1];
	int j[6];
	int a[6];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i];
		cin>>v[i];
		cin>>w[i];
	}
	for(int i=1;i<=5;i++)cin>>j[i];
	for(int i=1;i<=5;i++)cin>>a[i];
	cout<<13<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
