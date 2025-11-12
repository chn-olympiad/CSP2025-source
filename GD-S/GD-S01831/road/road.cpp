#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,sum;
bool pd;
vector<pair<int,int> >v[N]; 
struct node
{
	int c,u[N];
}a[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
		sum+=z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i].c;
		if(a[i].c)pd=1; 
		for(int j=1;j<=n;j++)
		{
			cin>>a[i].u[j];	
			if(a[i].u[j])pd=1;
		} 
	}
	if(pd==0)
	{
		cout<<0;
		return 0;
	}
	else
	{
		cout<<sum;
	}
	return 0;
}
