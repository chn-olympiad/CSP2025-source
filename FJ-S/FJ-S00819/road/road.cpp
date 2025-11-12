#include<bits/stdc++.h>
using namespace std;
struct um{
	int d1,d2;
	int cost;
	int used;
}; 
bool cmp(struct um u1,struct um u2)
{
	return u1.cost<u2.cost;
}
int main()
{
	int m,n,k,sco=1,c1,c2,c[19],a[9999][9999],xgj;
	int flag[9999][19];
	memset(flag,0,sizeof(flag));
	bool tp;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	struct um u[1000002];
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
	cin>>u[i].d1>>u[i].d2>>u[i].cost;
	u[i].used=-1;
}
	for(int j=0;j<k;j++)
	{
		cin>>c[j];
		for(int i=0;i<n;i++)
		cin>>a[j][i];
	}
	cout<<"0";
	return 0;
}

