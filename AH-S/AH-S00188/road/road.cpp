#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k,s=0,a[10001],b[10001],c[10001];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		if(i%2==0)
		{
			s+=c[i];
		}
	}
	for(int i=1;i<=k;i++)
	{
		int q,w,e,r,t;
		cin>>q>>w>>e>>r>>t;
		s=s+t-c[i/2+1];
	}
	cout<<s*2+1;
	return 0;
}
