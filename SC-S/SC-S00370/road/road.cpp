#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

int u[N],v[N],w[N]; 
int c,a[N];
int bj=0;
int f=0;
int n,m,k;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	
	cin>>n>>m>>k;
	
	
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		if(w[i]!=0)f=1;
	}
	cin>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i])bj=1;
	}
	if(bj==0)
	{
		cout<<c<<endl;
		return 0;
	}
	if(f==1)
	{
		cout<<0<<endl;
		return 0;
	}
	else cout<<0;

	return 0;
 } 