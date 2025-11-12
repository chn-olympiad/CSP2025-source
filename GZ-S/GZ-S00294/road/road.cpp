//GZ-S00249 遵义市南白中学 毛华健 
#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,a[10000],b[1000],c[10000],d[10000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	
	cout<<a[2]+b[2]+c[2];
	return 0;
}
