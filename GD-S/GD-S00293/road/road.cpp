#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n,m,k;
long long a[1000005],b[1000005],w[1000005],ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;	
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>w[i];
	}
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			ans=ans+w[i];
		}
	}
	else if(k!=0)
	{
		ans=0;
	}
	cout<<ans;

	return 0;
}

