#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
int u[N],v[N],w[N];
int a[N];
long long int s;
int main()
{	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		s+=w[i];
	}
	if(k!=0)
	{
		cout<<s;
	}
	else
	{
		cout<<0;
	}
}
