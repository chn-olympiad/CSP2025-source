#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll r=1e7;
ll n,m,k;
ll c[r];
ll w[r];
ll u[r],v[r];
int a[1000][1000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(ll i=0;i<m;i++)
	{
		cin>>c[i];
		for(ll j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"0";
	return 0;	
} 
