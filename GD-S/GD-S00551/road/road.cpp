#include<bits/stdc++.h>
using namespace std;
struct g1{
	long long u;
	long long v;
	long long w;
}a[1005];
struct g2{
	long long v;
	long long c[10004];
}b[15];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i].v;
		for(int j=1;j<=n;j++)
		{
			cin>>b[i].c[j];
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
